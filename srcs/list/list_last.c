/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_last.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:07:17 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:07:32 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdlib.h>

t_file	*list_last(t_file *file_list)
{
	if (!file_list)
		return (NULL);
	while (file_list->next)
		file_list = file_list->next;
	return (file_list);
}
