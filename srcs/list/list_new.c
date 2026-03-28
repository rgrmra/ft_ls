/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_new.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:00:38 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/28 17:07:28 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

static const char	*basename(const char *file_path)
{
	const char	*file_name;

	// change strrchr to ft_strrchr
	file_name = strrchr(file_path, '/');
	if (file_name)
		return (&file_name[1]);
	return (file_path);
}

t_file	*list_new(const char *file_path)
{
	t_file		*file;

	file = (t_file *) malloc(sizeof(t_file));
	if (!file)
	{
		printf("ft_ls: cannot access '%s': %s\n", file_path, strerror(errno));
		return (NULL);
	}
	//	change strdup to ft_strdup
	file->name = strdup(basename(file_path));
	//	change strdup to ft_strdup
	file->path = strdup(file_path);
	file->next = NULL;
	return (file);
}
