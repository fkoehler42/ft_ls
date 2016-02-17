/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handling.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/16 15:24:48 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 20:19:27 by fkoehler         ###   ########.fr       */
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
	new->path = ft_strjoin(tmp, file);
	free(tmp);
	if (flag->path->file == NULL)
		flag->path->file = new;
	else
		sort_file(flag, new);
	return (1);
}

int		read_path(t_flag *flag, char *path)
{
	DIR	*dirp;
	struct dirent *file;

	if ((dirp = opendir(path)) == NULL)
		return (0);
	while ((file = readdir(dirp)) != NULL)
		add_file(flag, file->d_name);
	print_files(flag);
	closedir(dirp);
	if (flag->rec)
		recursive_path(flag);
	return (1);
}
