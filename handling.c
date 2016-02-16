/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/16 18:22:13 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		store_file(t_path **path, char *file)
{
	t_file	*new;
	t_file	*tmp;

	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->f_name = ft_strdup(file);
	new->next = NULL;
	ft_putendl(new->f_name);
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

int		open_path(t_path **path, char *p_name)
{
	DIR	*dirp;
	struct dirent *file;
	t_path **tmp;

	if (path == NULL)
		return (0);
	tmp = path;
	while (*tmp != NULL)
	{
		if ((dirp = opendir(p_name)) == NULL)
			return (0);
		while ((file = readdir(dirp)) != NULL)
		{
			if ((*tmp)->flags->rec && file->d_type == DT_DIR)
				set_path(path, (*path)->flags, file->d_name);
			store_file(tmp, file->d_name);
		}
		*tmp = (*tmp)->next;
	}
	return (1);
}
