/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 20:15:38 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		set_flags(char *arg, t_flag *flag)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'a')
			flag->a = 1;
		else if (arg[i] == 'l')
			flag->l = 1;
		else if (arg[i] == 'r')
			flag->r = 1;
		else if (arg[i] == 'R')
			flag->rec = 1;
		else if (arg[i] == 't')
			flag->t = 1;
		else
			return (0);
		i++;
	}
	return (i == 0 ? 0 : 1);
}

int		add_path(t_flag *flag, char *arg)
{
	t_path *new;
	t_path *tmp;

	if (!(new = (t_path *)malloc(sizeof(*new))))
		return (0);
	new->p_name = ft_strdup(arg);
	new->next = NULL;
	new->file = NULL;
	if (flag->path == NULL)
		flag->path = new;
	else
	{
		tmp = flag->path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
