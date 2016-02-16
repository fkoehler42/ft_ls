/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/16 15:26:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		store_file(t_path **path, char *file)
{
	t_file	*new;
	t_file	*tmp;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->name = file;
	new->next = NULL;
	ft_putendl(new->name);
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
			store_file(path, file->d_name);
		*path = (*path)->next;
	}
	return (1);
}
