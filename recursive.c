/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:31:56 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 17:46:12 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		insert_path(t_path **path, char *path_name)
{
	t_path	*new;
	t_path	*tmp;

	if (!(new = (t_path *)malloc(sizeof(*new))))
		return (0);
	new->p_name = ft_strdup(path_name);
	new->next = NULL;
	new->file = NULL;
	if (((*path)->next) == NULL)
		(*path)->next = new;
	else
	{
		tmp = *path;
		(*path)->next = new;
		new->next = tmp->next;
	}
	return (1);
}

void	recursive_path(t_path *path)
{
	t_file 	*tmp;
	struct 	stat buf;
	char	*new_path;
	char 	*join;

	new_path = NULL;
	join = NULL;
	tmp = path->file;
	while (tmp)
	{
		if ((stat(tmp->path, &buf)) < 0)
			return ;
		if (S_ISDIR(buf.st_mode))
		{
			join = ft_strjoin(path->p_name, "/");
			new_path = ft_strjoin(join, tmp->f_name);
			free(join);
			insert_path(&path, new_path);
			ft_putendl(new_path);
			free(new_path);
		}
		tmp = tmp->next;
	}
}
