/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 18:17:54 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/22 18:09:20 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <sys/stat.h>

# define SYMLINK_MAX_SIZE 256

typedef struct s_file
{
	char			*name;
	char			*path;
	struct stat		stat;
	struct s_file	*next;
}	t_file;

typedef struct s_time
{
	char	*weekday;
	char	*month;
	char	*day;
	char	*hour;
	char	*minutes;
	char	*seconds;
	char	*year;
}	t_time;

typedef enum e_flag
{
	FT_LS_LOWER_L = 1 << 0,
	FT_LS_UPPER_R = 1 << 1,
	FT_LS_LOWER_R = 1 << 2,
	FT_LS_LOWER_A = 1 << 3,
	FT_LS_LOWER_T = 1 << 4,
	FT_LS_LOWER_U = 1 << 5,
	FT_LS_LOWER_F = 1 << 6,
	FT_LS_LOWER_G = 1 << 6,
	FT_LS_LOWER_D = 1 << 8,
	
}	t_flag;

#endif
