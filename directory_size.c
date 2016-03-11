/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   directory_size.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 17:54:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int	count_blocks(t_flag *flag)
{
	int		blocks;
	t_file	*tmp;

	blocks = 0;
	tmp = flag->file;
	while (tmp)
	{
		blocks += tmp->stat.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}
