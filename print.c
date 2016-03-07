/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 20:35:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_flag *flag)
{
	t_file	*tmp;

	if (!(tmp = flag->file))
		return ;
	if (flag->l && (ft_strcmp(tmp->f_name, tmp->f_path) != 0))
		ft_printf("total %d\n", count_blocks(flag));
	while (tmp)
	{
		if (flag->l)
			print_files_infos(flag, tmp);
		else
			ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}

void	print_files_infos(t_flag *flag, t_file *file)
{
	char	link_target[1024];

	ft_bzero(link_target, 1024);
	print_file_type(&file->stat);
	print_owner_perms(&file->stat);
	print_group_perms(&file->stat);
	print_other_perms(&file->stat);
	ft_printf("%*d %-*s%-*s", (flag->max_char_link + 2), file->stat.st_nlink,
	(flag->max_char_owner + 2), file->owner,
	(flag->max_char_group + 2), file->group);
	flag->max_char_dev > 0 ? print_file_size(flag, &file->stat) :
	ft_printf("%*d ", flag->max_char_size, file->stat.st_size);
	print_file_time(&file->stat);
	if (S_ISLNK(file->stat.st_mode))
	{
		if (readlink(file->f_path, link_target, 1023) < 0)
		{
			ft_putstr_fd("ft_ls: ", 2);
			perror(file->f_name);
		}
		else
			ft_printf("%s -> %s\n", file->f_name, link_target);
	}
	else
		ft_putendl(file->f_name);
}
