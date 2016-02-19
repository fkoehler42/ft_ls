/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/19 12:52:51 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lexicographical_order(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2));
}

int		rev_lexicographical_order(char *s1, char *s2)
{
	return (-(ft_strcmp(s1, s2)));
}

void	sort_path(t_flag *flag, t_path *new)
{
	t_path *tmp;

	tmp = flag->path;
	if ((flag->(*fptr)(new->p_name, tmp->p_name)) <= 0)
	{
		flag->path = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->(*fptr)(new->p_name, tmp->next->p_name)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}

void	sort_file(t_flag *flag, t_file *new)
{
	t_file *tmp;

	tmp = flag->file;
	if ((flag->(*fptr)(new->f_name, tmp->f_name)) <= 0)
	{
		flag->file = new;
		new->next = tmp;
	}
	else
	{
		while (tmp->next && ((flag->(*fptr)(new->f_name, tmp->next->f_name)) > 0))
			tmp = tmp->next;
		new->next = tmp->next;
		tmp->next = new;
	}
}
