/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 15:55:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	sort_path1(t_flag *flag, t_path *new)
{
	t_path *tmp;

	if (!(flag->fptr1))
		sort_path2(flag, new);
	else
	{
		tmp = flag->path;
		if ((flag->fptr1(new->p_name, tmp->p_name)) <= 0)
		{
			flag->path = new;
			new->next = tmp;
		}
		else
		{
			while (tmp->next && ((flag->fptr1(new->p_name,
					tmp->next->p_name)) > 0))
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}

void	sort_path2(t_flag *flag, t_path *new)
{
	t_path *tmp;

	tmp = flag->path;
	if ((flag->fptr2(new->p_name, tmp->p_name, &new->stat, &tmp->stat)) <= 0)
	{
		flag->path = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->fptr2(new->p_name, tmp->next->p_name,
				&new->stat, &tmp->next->stat)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	sort_file1(t_flag *flag, t_file *new)
{
	t_file *tmp;

	if (!(flag->fptr1))
		sort_file2(flag, new);
	else
	{
		tmp = flag->file;
		if ((flag->fptr1(new->f_name, tmp->f_name)) <= 0)
		{
			flag->file = new;
			new->next = tmp;
		}
		else
		{
			while (tmp->next &&
					((flag->fptr1(new->f_name, tmp->next->f_name)) > 0))
				tmp = tmp->next;
			new->next = tmp->next;
			tmp->next = new;
		}
	}
}

void	sort_file2(t_flag *flag, t_file *new)
{
	t_file *tmp;

	tmp = flag->file;
	if ((flag->fptr2(new->f_name, tmp->f_name, &new->stat, &tmp->stat)) <= 0)
	{
		flag->file = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->fptr2(new->f_name, tmp->next->f_name,
				&new->stat, &tmp->next->stat)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
