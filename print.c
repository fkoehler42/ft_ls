/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 14:02:52 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files(t_flag *flag)
{
	t_file	*tmp;

	tmp = flag->file;
	if (flag->l && (ft_strcmp(tmp->f_name, tmp->f_path) != 0))
		ft_printf("total %d\n", count_blocks(flag));
	while (tmp)
	{
		if (flag->l)
			print_files_infos(tmp);
		else
			ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}

void	print_files_infos(t_file *file)
{
	struct	stat buf;
	char	link_target[1024];

	ft_bzero(link_target, 1024);
	lstat(file->f_path, &buf);
	print_file_type(buf);
	print_owner_perms(buf);
	print_group_perms(buf);
	print_other_perms(buf);
	ft_printf("%3d ", buf.st_nlink);
	print_user_and_group(buf);
	ft_printf("%7d ", buf.st_size);
	print_file_time(buf);
	if (S_ISLNK(buf.st_mode))
	{
		if (readlink(file->f_path, link_target, sizeof(link_target)) < 0)
			perror("ft_ls");
		ft_printf("%s -> %s\n", file->f_name, link_target);
	}
	else
		ft_putendl(file->f_name);
}
