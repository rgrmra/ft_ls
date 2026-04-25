/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/07 17:21:04 by rde-mour          #+#    #+#             */
/*   Updated: 2026/04/25 17:18:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "list.h"
#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <pwd.h>
#include <grp.h>
#include <unistd.h>
#include <time.h>
#include <dirent.h>
#include "sort.h"

typedef struct s_test
{
	int	link;
	int	user;
	int	group;
	int	block;
}	t_test;

char *get_symlink_name(const char *file_path, struct stat file_stat)
{
	ssize_t	size;
	char	*buffer;

	if (!S_ISLNK(file_stat.st_mode))
		return (NULL);
	buffer = malloc(sizeof(unsigned char) * SYMLINK_MAX_SIZE);
	if (!buffer)
		return (NULL);
	size = readlink(file_path, buffer, SYMLINK_MAX_SIZE);
	buffer[size] = '\0';
	if (size)
		return (buffer);
	free(buffer);
	return (NULL);
}

void	free_time(t_time *time)
{
	if (!time)
		return ;
	free(time->weekday);
	free(time->month);
	free(time->day);
	free(time->hour);
	free(time->minutes);
	free(time->seconds);
	free(time->year);
	free(time);
}

t_time	*get_time(time_t raw_time)
{
	char	*file_time;
	t_time	*time;

	file_time = ctime(&raw_time);
	if (!file_time)
		return (NULL);
	time = (t_time *) malloc(sizeof(t_time));
	if (!time)
		return (NULL);
	// change strndup to ft_strndup
	time->weekday = strndup(file_time, 3);
	time->month = strndup(file_time + 4, 3);
	time->day = strndup(file_time + 8, 2);
	time->hour = strndup(file_time + 11, 2);
	time->minutes = strndup(file_time + 14, 2);
	time->seconds = strndup(file_time + 17, 2);
	time->year = strndup(file_time + 20, 4);
	return (time);
}

static char	get_acl_file_type(mode_t mode)
{
	if (S_ISREG(mode))
		return '-';
	if (S_ISDIR(mode))
		return 'd';
	if (S_ISLNK(mode))
		return 'l';
	if (S_ISCHR(mode))
		return 'c';
	if (S_ISBLK(mode))
		return 'b';
	if (S_ISFIFO(mode))
		return 'p';
	if (S_ISSOCK(mode))
		return 's';
	return '?';
}

static char	get_acl_file_access(mode_t file_mode, mode_t mode)
{
	if (mode & file_mode)
	{
		if (mode & (S_IRUSR | S_IRGRP | S_IROTH))
			return 'r';
		if (mode & (S_IWUSR | S_IWGRP | S_IWOTH))
			return 'w';
		if (mode & (S_IXUSR | S_IXGRP | S_IXOTH))
			return 'x';
	}
	return '-';
}

char	*get_acl(mode_t	mode)
{
	char	*acl;

	acl = (char *) malloc(sizeof(char) * 11);
	if (!acl)
		return (NULL);
	acl[0] = get_acl_file_type(mode);
	acl[1] = get_acl_file_access(mode, S_IRUSR);
	acl[2] = get_acl_file_access(mode, S_IWUSR);
	acl[3] = get_acl_file_access(mode, S_IXUSR);
	acl[4] = get_acl_file_access(mode, S_IRGRP);
	acl[5] = get_acl_file_access(mode, S_IWGRP);
	acl[6] = get_acl_file_access(mode, S_IXGRP);
	acl[7] = get_acl_file_access(mode, S_IROTH);
	acl[8] = get_acl_file_access(mode, S_IWOTH);
	acl[9] = get_acl_file_access(mode, S_IXOTH);
	acl[10] = '\0';
	return (acl);
}

t_file	*get_list_last(t_file *file_list)
{
	if (!file_list)
		return (NULL);
	while (file_list->next)
		file_list = file_list->next;
	return (file_list);
}

void	parse_flags(char *entries, t_flag *flags)
{
	while (*(++entries))
	{
		if (*entries == 'l')
			*flags |= FT_LS_LOWER_L;
		else if (*entries == 'a')
			*flags |= FT_LS_LOWER_A;
		else if (*entries == 'r')
			*flags |= FT_LS_LOWER_R;
		else if (*entries == 'R')
			*flags |= FT_LS_UPPER_R;
		else if (*entries == 't')
			*flags |= FT_LS_LOWER_T;
		else if (*entries == 'u')
			*flags |= FT_LS_LOWER_U;
		else if (*entries == 'f')
			*flags |= FT_LS_LOWER_F;
		else if (*entries == 'g')
			*flags |= FT_LS_LOWER_G;
		else if (*entries == 'd')
			*flags |= FT_LS_LOWER_D;
		else
		{
			printf("ft_ls: invalid option -- '%c'\n", *entries);
			*flags |= FT_LS_ERROR;
			break;
		}
	}
}

t_file	*get_stat(t_file *file)
{
	if (lstat(file->path, &file->stat) == -1)
	{
		// remove printf
		printf("ft_ls: cannot access '%s': %s\n", file->path, strerror(errno));
		return (NULL);
	}
	return (file);
}

t_file	*get_dir_files(const char *file_path)
{
	DIR				*directory;
	struct dirent	*file_data;
	t_file			*file_list;
	t_file			*file;
	char			buffer[4096];

	file_list = NULL;
	directory = opendir(file_path);
	if (!directory)
		return (NULL);
	while (1)
	{
		file_data = readdir(directory);
		if (!file_data)
			break ;
		if (file_data->d_name[0] == '.')
			continue ;
		sprintf(buffer, "%s/%s", file_path, file_data->d_name);
		file = list_new(buffer);
		if (file)
		{
			get_stat(file);
			list_add_back(&file_list, file);
		}
	}
	closedir(directory);
	return (file_list);
};

t_file	*parse(char **entries, t_flag *flags)
{
	t_file	*file_list;
	t_file	*file;
	char	*entry;

	file_list = NULL;
	while (*(++entries))
	{
		entry = *entries;
		if (entry[0] == '-' && entry[1] != '\0')
		{
			parse_flags(*entries, flags);
			continue ;
		}
		file = list_new(*entries);
		if (file)
			list_add_back(&file_list, file);
	}
	if (!file_list)
		file_list = list_new(".");
	return (file_list);
}

size_t	get_total_bytes(t_file *file_list)
{
	size_t	total_bytes;

	total_bytes = 0;
	while (file_list)
	{
		total_bytes += file_list->stat.st_blocks;
		file_list = file_list->next;
	}
	return (total_bytes / 2);
}

int	count_digits(int nbr)
{
	int	value;

	value = 0;
	while (nbr)
	{
		nbr /= 10;
		value++;
	}
	return (value);
}

void	count(t_file *file_list, t_test *test)
{
	int		size;
	t_file	*file;
	struct group	*gid;
	struct passwd	*uid;

	file = file_list;
	while (file)
	{
		size = 0;
		uid = getpwuid(file->stat.st_gid);
		if (uid)
			size = strlen(uid->pw_name);
		else
			size = count_digits(file->stat.st_uid);
		if (size > test->user)
			test->user = size;
		size = 0;
		gid = getgrgid(file->stat.st_gid);
		if (gid)
			size = strlen(gid->gr_name);
		else
			size = count_digits(file->stat.st_gid);
		if (size > test->group)
			test->group = size;
		size = count_digits(file->stat.st_nlink);
		if (size > test->link)
			test->link = size;
		size = count_digits(file->stat.st_size);
		if (size > test->block)
			test->block = size;
		file = file->next;
	}
}

void	test(t_file *file, t_test ctest)
{
	char	buffer[10];
	char	*link_name;
	struct group	*gid;
	struct passwd	*uid;

	if (!file)
		return ;
	link_name = get_symlink_name(file->path, file->stat);
	t_time	*time = get_time(file->stat.st_ctime);
	char	*acl = get_acl(file->stat.st_mode);
	printf("%s ", acl);
	sprintf(buffer, "%%%dld ", ctest.link);
    printf(buffer, (long)file->stat.st_nlink);
	uid = getpwuid(file->stat.st_uid);
	if (uid)
	{
		sprintf(buffer, "%%-%ds ", ctest.user);
    	printf(buffer, uid->pw_name);
	}
	else
	{
		sprintf(buffer, "%%-%dd ", ctest.user);
		printf(buffer, file->stat.st_uid);
	}
	sprintf(buffer, "%%-%ds ", ctest.group);
	gid = getgrgid(file->stat.st_gid);
	if (gid)
	{
		sprintf(buffer, "%%-%ds ", ctest.group);
		printf(buffer, gid->gr_name);
	}
	else
	{
		sprintf(buffer, "%%-%dd ", ctest.group);
		printf(buffer, file->stat.st_gid);
	}
	sprintf(buffer, "%%%dld ", ctest.block);
    printf(buffer, (long)file->stat.st_size);
	printf("%s %s %s:%s ", time->month, time->day, time->hour, time->minutes);
	printf("%s ", file->name);
	if (link_name)
		printf("-> %s", link_name);
	printf("\n");

	free(acl);
	free_time(time);
	if (link_name)
		free(link_name);
}

void	print(t_file *file_last, t_file *file_list, t_flag *flags)
{
	t_file	*file;
	t_test	ctest = {0};

	count(file_list, &ctest);
	//if (*flags & ~(FT_LS_LOWER_A))
		file_list = sort_list(file_list, SORT_NAME);
	file = file_list;
	if (list_size(file_last) > 1 || *flags & FT_LS_UPPER_R)
		printf("%s:\n", file_last->path);
	printf("total %lu\n", get_total_bytes(file));
	if (!file_list)
		return;
	while(file)
	{
		test(file, ctest);
		//printf("%s  ", file->name);
		file = file->next;
	}
	printf("\n");
	file = file_list;
	while (file)
	{
		//printf("test: %s:\n", file->path);
		if (S_ISDIR(file->stat.st_mode) && (*flags & FT_LS_UPPER_R))
			print(file, get_dir_files(file->path), flags);
		file = file->next;
	}
}

int	main(int argc, char **argv)
{
	t_file	*file;
	t_file	*files_list;
	t_flag	flags;

	(void) argc;
	flags = 0;
	files_list = parse(argv, &flags);
	if (flags == FT_LS_ERROR)
	{
		list_clear(&files_list);
		return (EXIT_FLAG_ERROR);
	}
	file = files_list;
	while (file)
	{
		get_stat(file);
		if (S_ISDIR(file->stat.st_mode))
			print(file, get_dir_files(file->path), &flags);
		else
			print(file, file, &flags);
		file = file->next;
	}
	list_clear(&files_list);
	return (EXIT_SUCCESS);
}
