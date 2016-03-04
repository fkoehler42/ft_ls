/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 19:21:25 by fkoehler         ###   ########.fr       */
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
		ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}

void	print_files_infos(t_file *file)
{
	struct	stat buf;

		if ((lstat(file->f_path, &buf)) < 0)
			perror("ft_ls");
		print_file_type(buf);
		print_owner_perms(buf);
		print_group_perms(buf);
		print_other_perms(buf);
		ft_printf("%3d ", buf.st_nlink);
		print_user_and_group(buf);
		ft_printf("%7d ", buf.st_size);
		//print_file_time(buf);
}
