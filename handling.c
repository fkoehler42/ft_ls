/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 18:09:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_file(t_flag *flag, char *file, char *path_name)
{
	t_file	*new;
	char	*tmp;

	if (!(flag->a) && file[0] == '.')
		return (1);
	if (!(new = (t_file *)malloc(sizeof(*new))))
		return (0);
	new->f_name = ft_strdup(file);
	new->next = NULL;
	tmp = ft_strjoin(path_name, "/");
	new->f_path = ft_strjoin(tmp, file);
	free(tmp);
	if (flag->file == NULL)
		flag->file = new;
	else
		sort_file(flag, new);
	return (1);
}

int		read_path(t_flag *flag, char *path_name)
{
	DIR	*dirp;
	struct dirent *file;

	flag->file = NULL;
	if ((dirp = opendir(path_name)) == NULL)
		return (0);
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, file->d_name, path_name);
	closedir(dirp);
	print_files(flag);
	if (flag->rec)
		recursive_path(flag);
	delete_files_list(flag);
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
