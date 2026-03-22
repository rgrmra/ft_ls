/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_front.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:09:02 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:10:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	list_add_front(t_file **file_list, t_file *list)
{
	if (!file_list || !list)
		return ;
	list->next = *file_list;
	*file_list = list;
}
