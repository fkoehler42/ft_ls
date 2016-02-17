/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 16:43:42 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_file(t_flag *flag, char *file)
{
	t_file	*new;
	t_file	*tmp;

	if (!(flag->a) && file[0] == '.')
		return (1);
	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->f_name = ft_strdup(file);
	new->next = NULL;
	if (path->file == NULL)
		path->file = new;
	else
	{
		tmp = path->file;
		while (tmp)
			tmp = tmp->next;
		tmp = new;
	}
	return (1);
}

int		read_path(t_flag *flag)
{
	DIR	*dirp;
	struct dirent *file;

	if ((dirp = opendir(flag->path->p_name)) == NULL)
		return (0);
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, file->d_name);
	sort_files(flag);
	return (1);
}
