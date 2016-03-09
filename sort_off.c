/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_off.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 11:09:57 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/09 11:13:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	no_sorting_path(t_flag *flag, t_path *new)
{
	t_path	*tmp;

	tmp = flag->path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}

void	no_sorting_file(t_flag *flag, t_file *new)
{
	t_file	*tmp;

	tmp = flag->file;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
}
