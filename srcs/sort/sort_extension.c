/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_extension.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:24:58 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 18:20:44 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <sys/stat.h>
#include <string.h>

static const char	*get_extension(const char *name)
{
	const char	*dot;

	dot = strrchr(name, '.');
	if (dot)
		return (dot + 1);
	return ("");
}

int	sort_extension(t_file *a, t_file *b)
{
	const char	*ext_a;
	const char	*ext_b;
	int			res;

	ext_a = get_extension(a->name);
	ext_b = get_extension(b->name);
	res = strcasecmp(ext_a, ext_b);
	if (res != 0)
		return (res);
	return (strcasecmp(a->name, b->name));
}
