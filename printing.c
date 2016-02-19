/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/19 15:03:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_flag *flag, char *path_name)
{
	t_file	*tmp;

	tmp = flag->file;
	ft_putstr(path_name);
	ft_putendl(":");
	while (tmp)
	{
		ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
	ft_putchar('\n');
}
