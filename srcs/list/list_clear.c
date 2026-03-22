/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_clear.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:04:23 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:15:08 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "list.h"
#include <stdlib.h>

void	list_clear(t_file **file_list)
{
	t_file	*file;

	if (!file_list)
		return ;
	while (*file_list)
	{
		file = *file_list;
		*file_list = (*file_list)->next;
		free(file->name);
		free(file->path);
		free(file);
	}
	*file_list = NULL;
}
