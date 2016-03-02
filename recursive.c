/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:31:56 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 18:16:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_path(t_flag *flag)
{
	t_file 	*tmp;
	struct 	stat buf;

	tmp = flag->file;
	while (tmp)
	{
		if ((stat(tmp->f_path, &buf)) < 0)
			return ;
		if (flag->a && (S_ISDIR(buf.st_mode)))
		{
			if (((ft_strcmp(".", tmp->f_name)) != 0)
				&& ((ft_strcmp("..", tmp->f_name)) != 0))
			{
				ft_printf("\n%s:\n", tmp->f_path);
				read_path(flag, tmp->f_path);
			}
		}
		else if (S_ISDIR(buf.st_mode))
		{
			ft_printf("\n%s\n", tmp->f_path);
			read_path(flag, tmp->f_path);
		}
		tmp = tmp->next;
	}
}
