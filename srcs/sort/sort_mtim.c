/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_mtim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:24:15 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 17:56:57 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

int	sort_mtim(t_file *a, t_file *b)
{
	if (a->stat.st_mtim.tv_sec > b->stat.st_mtim.tv_sec)
		return (1);
	if (a->stat.st_mtim.tv_sec < b->stat.st_mtim.tv_sec)
		return (-1);
	if (a->stat.st_mtim.tv_nsec > b->stat.st_mtim.tv_nsec)
		return (1);
	if (a->stat.st_mtim.tv_nsec < b->stat.st_mtim.tv_nsec)
		return (-1);
	return (0);
}
