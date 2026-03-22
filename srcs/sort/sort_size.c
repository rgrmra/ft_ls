/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:24:00 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 18:19:27 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	sort_size(t_file *a, t_file *b)
{
	if (a->stat.st_size > b->stat.st_size)
		return (-1);
	if (a->stat.st_size < b->stat.st_size)
		return (1);
	return (0);
}
