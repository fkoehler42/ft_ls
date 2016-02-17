/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 17:03:35 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	alphabetical_order(t_path *path)
{
	t_file	*tmp1;
	t_file	*tmp2;

	tmp1 = path->file;
	tmp2 = tmp;
	while (tmp->next)
	{
		if ((ft_strcmp(tmp->f_name, tmp->next->f_name)) > 0)
		{
			tmp2
		}
	}
}

void	sort_files(t_flag *flag)
{
	alphabetical_order(flag->path);
}
