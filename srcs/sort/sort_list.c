/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:23:25 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 18:09:02 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include "sort.h"
#include <stdlib.h>

static t_file	*sortcmp(t_file *file_list, int (*cmp)(t_file *, t_file *))
{
	t_file	*sorted;
	t_file	*current;
	t_file	**file;

	sorted = NULL;
	while (file_list)
	{
		current = file_list;
		file_list = file_list->next;
		file = &sorted;
		while (*file && cmp(current, *file) > 0)
			file = &(*file)->next;
		current->next = *file;
		*file = current;
	}
	return (sorted);
}

t_file	*sort_list(t_file *file_list, t_sort sort)
{
	if (sort & SORT_NAME)
		return (sortcmp(file_list, &sort_name));
	else if (sort & SORT_SIZE)
		return (sortcmp(file_list, &sort_size));
	else if (sort & SORT_MTIME)
		return (sortcmp(file_list, &sort_mtim));
	else if (sort & SORT_CTIME)
		return (sortcmp(file_list, &sort_ctim));
	else if (sort & SORT_ATIME)
		return (sortcmp(file_list, &sort_atim));
	else if (sort & SORT_EXTENSION)
		return (sortcmp(file_list, &sort_extension));
	else if (sort & SORT_VERSION)
		return (sortcmp(file_list, &sort_version));
	if (sort & SORT_REVERT)
		return (sortcmp(file_list, &sort_revert));
	return (file_list);
}
