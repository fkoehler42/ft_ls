/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 19:04:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_file(t_flag flag, t_path *path, char *file)
{
	t_file	*new;
	char	*tmp;

	if (!(flag.a) && file[0] == '.')
		return (1);
	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->f_name = ft_strdup(file);
	new->next = NULL;
	tmp = ft_strjoin(path->p_name, "/");
	new->path = ft_strjoin(tmp, file);
	free(tmp);
	if (path->file == NULL)
		path->file = new;
	else
		sort_file(flag, path, new);
	return (1);
}

int		read_path(t_flag flag, t_path *path, char *path_name)
{
	DIR	*dirp;
	struct dirent *file;

	if ((dirp = opendir(path_name)) == NULL)
		return (0);
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, path, file->d_name);
	closedir(dirp);
	print_files(path);
	if (flag.rec)
		recursive_path(flag, path);
	return (1);
}
