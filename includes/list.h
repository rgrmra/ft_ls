/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 16:02:49 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 16:14:35 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIST_H
# define LIST_H

# include "ft_ls.h"

void	list_add_back(t_file **file_list, t_file *list);
void	list_add_front(t_file **file_list, t_file *list);
void	list_clear(t_file **file_list);
t_file	*list_last(t_file *file_list);
t_file	*list_new(const char *file_path);

#endif
