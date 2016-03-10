/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/10 20:45:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_symlink(t_flag *flag, t_file *file)
{
	char	link_target[1024];

	ft_bzero(link_target, 1024);
	if (readlink(file->f_path, link_target, 1023) < 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(file->f_name);
	}
	else
	{
		if (flag->color)
			print_files_colorized(&file->stat, file->f_name);
		else
			ft_putstr(file->f_name);
		ft_printf(" -> %s\n", link_target);
	}
}

void	print_files_no_row(t_flag *flag)
{
	t_file *tmp;

	tmp = flag->file;
	while (tmp)
	{
		if (flag->color)
		{
			print_files_colorized(&tmp->stat, tmp->f_name);
			ft_putchar('\n');
		}
		else
			ft_putendl(tmp->f_name);
		tmp = tmp->next;
	}
}

void	print_files_colorized(struct stat *file, char *f_name)
{
	if (S_ISBLK((*file).st_mode))
		ft_printf(BLUE"%s"OFF, f_name);
	else if (S_ISCHR((*file).st_mode))
		ft_printf(GREEN"%s"OFF, f_name);
	else if (S_ISDIR((*file).st_mode))
		ft_printf(CYAN"%s"OFF, f_name);
	else if (S_ISLNK((*file).st_mode))
		ft_printf(PURPLE"%s"OFF, f_name);
	else if (S_ISSOCK((*file).st_mode))
		ft_printf(YELLOW"%s"OFF, f_name);
	else if (S_ISFIFO((*file).st_mode))
		ft_printf(RED"%s"OFF, f_name);
	else
		ft_putstr(f_name);
}

void	print_files(t_flag *flag)
{
	t_file	*tmp;

	if (!(tmp = flag->file))
		return ;
	if (flag->l || flag->g)
	{
		if (ft_strcmp(tmp->f_name, tmp->f_path) != 0)
			ft_printf("total %d\n", count_blocks(flag));
		while (tmp)
		{
			print_files_infos(flag, tmp);
			tmp = tmp->next;
		}
	}
	else if (flag->one || print_files_in_row(flag) < 0)
		print_files_no_row(flag);
}

void	print_files_infos(t_flag *flag, t_file *file)
{
	char	*perms;

	perms = ft_strdup("---------");
	print_file_type(&file->stat);
	set_owner_and_group_perms(&file->stat, perms);
	set_other_perms(&file->stat, perms);
	ft_putstr(perms);
	free(perms);
	if (flag->l)
		ft_printf("%*d %-*s%-*s", (flag->max_char_link +
		(print_file_attr(file))), file->stat.st_nlink,
		(flag->max_char_owner + 2), file->owner, (flag->max_char_group + 2),
		file->group);
	else if (flag->g)
		ft_printf("%*d %-*s", (flag->max_char_link + (print_file_attr(file))),
		file->stat.st_nlink, (flag->max_char_group + 2), file->group);
	flag->max_char_dev > 0 ? print_file_size(flag, &file->stat) :
	ft_printf("%*d ", flag->max_char_size, file->stat.st_size);
	print_file_time(&file->stat);
	if (S_ISLNK(file->stat.st_mode))
		print_symlink(flag, file);
	else
	{
		if (flag->color)
			print_files_colorized(&file->stat, file->f_name);
		else
			ft_putstr(file->f_name);
		ft_putchar('\n');
	}
}
