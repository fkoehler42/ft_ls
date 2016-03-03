/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 17:40:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_flag *flag)
{
	t_file	*tmp;

	tmp = flag->file;
	if (flag->l)
		print_files_infos(flag);
	else
	{
		while (tmp)
		{
			ft_putendl(tmp->f_name);
			tmp = tmp->next;
		}
	}
}

void	print_files_infos(t_flag *flag)
{
	t_file *tmp;
	struct	stat buf;

	tmp = flag->file;
	ft_printf("total %d\n", count_blocks(flag));
	while (tmp)
	{
		if ((lstat(tmp->f_path, &buf)) < 0)
			return ;
		print_file_type(buf);
		print_owner_perms(buf);
		print_group_perms(buf);
		print_other_perms(buf);
		ft_printf("%3d ", buf.st_nlink);
		print_user_and_group(buf);
		ft_printf("%7d ", buf.st_size);
		print_file_time(buf);
		ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}
