/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/13 18:04:10 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		set_flags(char *arg, t_flags *flags)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'a')
			flags->a = 1;
		else if (arg[i] == 'l')
			flags->l = 1;
		else if (arg[i] == 'r')
			flags->r = 1;
		else if (arg[i] == 'R')
			flags->R = 1;
		else if (arg[i] == 't')
			flags->t = 1;
		else
			return (0);
		i++;
	}
	return (i == 0 ? 0 : 1);
}

t_path	*set_path(t_path *path, char *arg)
{
	t_path *new;
	t_path *tmp;

	if (!(new = (t_path *)malloc(sizeof(*new))))
		return (NULL);
	new->path = strdup(arg);
	new->next = NULL;
	if (path == NULL)
		return (new);
	tmp = path;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = new;
	return (path);
}
