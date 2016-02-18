/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting_paths.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 18:01:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	path_lexicographical_order(t_path *path, t_path *new)
{
	t_path	*tmp;

	tmp = path;
	if ((ft_strcmp(new->p_name, tmp->p_name)) <= 0)
	{
		path = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((ft_strcmp(new->p_name, tmp->next->p_name)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	path_rev_lexicographical_order(t_path *path, t_path *new)
{
	t_file	*tmp;

	tmp = path->file;
	if ((ft_strcmp(new->f_name, tmp->f_name)) >= 0)
	{
		path->file = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((ft_strcmp(new->f_name, tmp->next->f_name)) < 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	sort_path(t_flag flag, t_path *path, t_path *new)
{
	if (flag.r)
		path_rev_lexicographical_order(path, new);
	else
		path_lexicographical_order(path, new);
}
