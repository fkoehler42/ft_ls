/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 19:46:38 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_flag *flag)
{
	t_file	*tmp;

	tmp = flag->file;
	if (flag->l)
		ft_printf("total %d\n", count_blocks(flag));
	while (tmp)
	{
		ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}

int		count_blocks(t_flag *flag)
{
	int		blocks;
	t_file	*tmp;
	struct	stat buf;

	blocks = 0;
	tmp = flag->file;
	while (tmp)
	{
		if ((stat(tmp->f_path, &buf)) < 0)
			return (-1);
		blocks += buf.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}
