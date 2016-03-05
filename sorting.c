/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 17:34:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lexico_order(char *s1, char *s2, struct stat f1, struct stat f2)
{
	struct stat tmp;

	tmp = f1;
	tmp = f2;
	return (ft_strcmp(s1, s2));
}

int		rev_lexico_order(char *s1, char *s2, struct stat f1, struct stat f2)
{
	struct stat tmp;

	tmp = f1;
	tmp = f2;
	return (-(ft_strcmp(s1, s2)));
}

void	sort_path(t_flag *flag, t_path *new)
{
	t_path *tmp;

	tmp = flag->path;
	if ((flag->fptr(new->p_name, tmp->p_name, new->stat, tmp->stat)) <= 0)
	{
		flag->path = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->fptr(new->p_name, tmp->next->p_name,
				new->stat, tmp->next->stat)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	sort_file(t_flag *flag, t_file *new)
{
	t_file *tmp;

	tmp = flag->file;
	if ((flag->fptr(new->f_path, tmp->f_path, new->stat, tmp->stat)) <= 0)
	{
		flag->file = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->fptr(new->f_path, tmp->next->f_path,
				new->stat, tmp->next->stat)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
