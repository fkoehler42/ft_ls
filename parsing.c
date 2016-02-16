/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/16 12:56:46 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "ft_ls.h"

int		store_file(t_path **path, struct dirent *file)
{
	t_file	*new;
	t_file	*tmp;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->next = NULL;
	if ((*path)->file == NULL)
		(*path)->file = new;
	else
	{
		tmp = (*path)->file;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}

int		open_path(t_path **path)
{
	DIR	*dirp;
	struct dirent *file;

	while ((*path) != NULL)
	{
		if (path == NULL)
			return (0);
		if ((dirp = opendir((*path)->path)) == NULL)
			return (0);
		while ((file = readdir(dirp)) != NULL)
			store_file(path, file);
		*path = (*path)->next;
	}
	return (1);
}

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
			flags->rec = 1;
		else if (arg[i] == 't')
			flags->t = 1;
		else
			return (0);
		i++;
	}
	return (i == 0 ? 0 : 1);
}

int		set_path(t_path **path, t_flags *flags , char *arg)
{
	t_path *new;
	t_path *tmp;

	if (!(new = (t_path *)malloc(sizeof(*new))))
		return (0);
	new->path = ft_strdup(arg);
	new->flags = flags;
	new->next = NULL;
	new->file = NULL;
	if (*path == NULL)
		*path = new;
	else
	{
		tmp = *path;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = new;
	}
	return (1);
}
