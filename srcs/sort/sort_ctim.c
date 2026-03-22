/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_ctim.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:24:43 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 17:56:34 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>

int	sort_ctim(t_file *a, t_file *b)
{
	if (a->stat.st_ctim.tv_sec > b->stat.st_ctim.tv_sec)
		return (1);
	if (a->stat.st_ctim.tv_sec < b->stat.st_ctim.tv_sec)
		return (-1);
	if (a->stat.st_ctim.tv_nsec > b->stat.st_ctim.tv_nsec)
		return (1);
	if (a->stat.st_ctim.tv_nsec < b->stat.st_ctim.tv_nsec)
		return (-1);
	return (0);
}
