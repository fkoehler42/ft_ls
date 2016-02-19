/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/19 13:03:11 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_file(t_flag *flag, char *file)
{
	t_file	*new;
	char	*tmp;

	if (!(flag->a) && file[0] == '.')
		return (1);
	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->f_name = ft_strdup(file);
	new->next = NULL;
	tmp = ft_strjoin(flag->path->p_name, "/");
	new->f_path = ft_strjoin(tmp, file);
	free(tmp);
	if (path->file == NULL)
		path->file = new;
	else
		sort_file(flag, path, new);
	return (1);
}

int		read_path(t_flag *flag, char *path_name)
{
	DIR	*dirp;
	struct dirent *file;

	if ((dirp = opendir(path_name)) == NULL)
		return (0);
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, path, file->d_name);
	closedir(dirp);
	print_files(path);
	if (flag->rec)
		recursive_path(flag, path);
	return (1);
}

int		add_path(t_flag *flag, char *arg)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(*new))))
		return (0);
	new->p_name = ft_strdup(arg);
	new->next = NULL;
	if (flag->path == NULL)
		flag->path = new;
	else
		sort_path(flag, new);
	return (1);
}
