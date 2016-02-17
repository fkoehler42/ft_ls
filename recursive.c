/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:31:56 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 20:40:29 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_path(t_flag *flag)
{
	t_file 	*tmp;
	struct 	stat buf;
	char	*new_path;
	char 	*join;

	new_path = NULL;
	join = NULL;
	tmp = flag->path->file;
	while (tmp)
	{
		if ((stat(tmp->path, &buf)) < 0)
			return ;
		if (S_ISDIR(buf.st_mode))
		{
			join = ft_strjoin(flag->path->p_name, "/");
			new_path = ft_strjoin(join, tmp->f_name);
			free(join);
			read_path(flag, new_path);
			free(new_path);
		}
		tmp = tmp->next;
	}
}
