/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recursive.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 19:31:56 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/19 15:15:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	recursive_path(t_flag *flag)
{
	t_file 	*tmp;
	struct 	stat buf;

	tmp = flag->file;
	while (tmp)
	{
		if ((stat(tmp->f_path, &buf)) < 0)
			return ;
		if (S_ISDIR(buf.st_mode))
			read_path(flag, tmp->f_path);
		tmp = tmp->next;
	}
}
