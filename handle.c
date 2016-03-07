/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 13:13:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		add_file(t_flag *flag, char *file, char *path_name)
{
	t_file	*new;
	char	*tmp;

	tmp = NULL;
	if (!(flag->a) && file[0] == '.')
		return (0);
	if (!(new = (t_file *)malloc(sizeof(*new))))
	{
		perror("ft_ls: malloc: ");
		return (-1);
	}
	new->f_name = ft_strdup(file);
	new->next = NULL;
	if (!path_name[0])
		new->f_path = ft_strdup(file);
	else
	{
		tmp = ft_strjoin(path_name, "/");
		new->f_path = ft_strjoin(tmp, file);
		free(tmp);
	}
	lstat(new->f_path, &new->stat);
	flag->file == NULL ? flag->file = new : sort_file1(flag, new);
	return (0);
}

int		read_path(t_flag *flag, char *path_name)
{
	DIR		*dirp;
	struct	dirent *file;
	char	*cut_path;

	flag->file = NULL;
	if (!(dirp = opendir(path_name)))
	{
		ft_putstr_fd("ft_ls: ", 2);
		(cut_path = (ft_strrchr(path_name, '/'))) ?
		perror(++cut_path) : perror(path_name);
		return (-1);
	}
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, file->d_name, path_name);
	closedir(dirp);
	print_files(flag);
	if (flag->rec)
		recursive_path(flag);
	delete_files_list(flag);
	return (0);
}

int		add_path(t_flag *flag, char *arg)
{
	t_path *new;

	if (!(new = (t_path *)malloc(sizeof(*new))))
	{
		perror("ft_ls: malloc: ");
		return (-1);
	}
	new->p_name = ft_strdup(arg);
	new->next = NULL;
	lstat(new->p_name, &new->stat);
	if (flag->path == NULL)
		flag->path = new;
	else
		sort_path1(flag, new);
	return (0);
}
