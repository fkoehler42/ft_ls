/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 19:02:38 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_path *path)
{
	t_file	*tmp;

	tmp = path->file;
	ft_putstr(path->p_name);
	ft_putendl(":");
	while (tmp)
	{
		ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
