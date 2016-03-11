/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_list.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 10:40:57 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 16:33:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	delete_files_list(t_flag *flag)
{
	t_file	*tmp1;
	t_file	*tmp2;

	tmp1 = flag->file;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1->f_name);
		free(tmp1->f_path);
		free(tmp1->owner);
		free(tmp1->group);
		free(tmp1);
		tmp1 = tmp2;
	}
	flag->file = NULL;
	flag->max_char_name = 0;
	flag->max_char_link = 0;
	flag->max_char_owner = 0;
	flag->max_char_group = 0;
	flag->max_char_size = 0;
	flag->max_char_dev = 0;
}

void	delete_paths_list(t_flag *flag)
{
	t_path	*tmp1;
	t_path	*tmp2;

	tmp1 = flag->path;
	while (tmp1 != NULL)
	{
		tmp2 = tmp1->next;
		free(tmp1->p_name);
		free(tmp1);
		tmp1 = tmp2;
	}
	flag->path = NULL;
}
