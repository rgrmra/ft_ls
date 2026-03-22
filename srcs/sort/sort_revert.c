/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_revert.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:25:41 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:27:26 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_file	*sort_revert(t_file *file_list)
{
	t_file	*list;
	t_file	*file;

	list = NULL;
	file = file_list;
	while (file_list)
	{
		file = file_list;
		file_list = file_list->next;
		file->next = list;
		list = file;
	}
	return (list);
}
