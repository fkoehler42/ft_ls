/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:31:56 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 14:45:45 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	free_elem(t_file *file)
{
	free(file->f_name);
	free(file->f_path);
	free(file->owner);
	free(file->group);
	free(file);
}

void		recursive_path(t_flag *flag)
{
	t_file	*tmp;
	t_file	*prev;

	tmp = flag->file;
	reset_field_widths(flag);
	while (tmp)
	{
		if (flag->a && (S_ISDIR(tmp->stat.st_mode)))
		{
			if (((ft_strcmp(".", tmp->f_name)) != 0)
				&& ((ft_strcmp("..", tmp->f_name)) != 0))
			{
				ft_printf("\n%s:\n", tmp->f_path);
				read_path(flag, tmp->f_path);
			}
		}
		else if (S_ISDIR(tmp->stat.st_mode))
		{
			ft_printf("\n%s:\n", tmp->f_path);
			read_path(flag, tmp->f_path);
		}
		prev = tmp;
		tmp = tmp->next;
		free_elem(prev);
	}
}
