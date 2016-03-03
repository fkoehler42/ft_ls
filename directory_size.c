/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 17:00:44 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_blocks(t_flag *flag)
{
	int		blocks;
	t_file	*tmp;
	struct	stat buf;

	blocks = 0;
	tmp = flag->file;
	while (tmp)
	{
		if ((lstat(tmp->f_path, &buf)) < 0)
			return (-1);
		blocks += buf.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}
