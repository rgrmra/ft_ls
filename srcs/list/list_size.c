/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/28 18:04:16 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/28 18:08:31 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include <ft_ls.h>
#include <stddef.h>

size_t	list_size(t_file *file_list)
{
	t_file	*file;
	size_t	size;

	size = 0;
	file = file_list;
	while (file)
	{
		size++;
		file = file->next;
	}
	return (size);
}
