/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rde-mour <rde-mour@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/08 15:27:16 by rde-mour          #+#    #+#             */
/*   Updated: 2026/03/08 18:17:38 by rde-mour         ###   ########.org.br   */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "ft_ls.h"

typedef enum e_sort
{
	SORT_NONE = 1 << 0,      // ls -U	# sem ordenação
	SORT_NAME = 1 << 1,      /* ls		# ordena por nome */
	SORT_SIZE = 1 << 2,      // ls -S	# ordena por tamanho
	SORT_MTIME = 1 << 3,     /* ls -t	# mais recentemente modificado primeiro */
	SORT_CTIME = 1 << 4,     // ls -c	# último mudança primeiro
	SORT_ATIME = 1 << 5,     // ls -u	# último acesso primeiro
	SORT_EXTENSION = 1 << 6, // ls -X	# ordena por extenção
	SORT_VERSION = 1 << 7,   // ls -v	# ordenação natural por versões
	SORT_REVERT = 1 << 8,    /* ls -r	# ordenação inversa */
}	t_sort;

t_file	*sort_list(t_file *file_list, t_sort sort);

int		sort_name(t_file *a, t_file *b);
int		sort_size(t_file *a, t_file *b);
int		sort_mtim(t_file *a, t_file *b);
int		sort_ctim(t_file *a, t_file *b);
int		sort_atim(t_file *a, t_file *b);
int		sort_extension(t_file *a, t_file *b);
int		sort_version(t_file *a, t_file *b);
int		sort_revert(t_file *a, t_file *b);

#endif
