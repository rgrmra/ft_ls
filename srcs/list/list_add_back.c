/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_add_back.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:05:50 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:09:16 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "list.h"

void	list_add_back(t_file **file_list, t_file *list)
{
	if (!file_list || !list)
		return ;
	if (!*file_list)
		*file_list = list;
	else
		list_last(*file_list)->next = list;
}
