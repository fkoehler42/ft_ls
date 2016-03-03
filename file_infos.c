/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_infos.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 15:48:11 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		count_blocks(t_flag *flag)
{
	int		blocks;
	t_file	*tmp;
	struct	stat buf;

	blocks = 0;
	tmp = flag->file;
	while (tmp)
	{
		if ((lstat(tmp->f_path, &buf)) < 0)
			return (-1);
		blocks += buf.st_blocks;
		tmp = tmp->next;
	}
	return (blocks);
}

void	print_file_type(struct stat file)
{
	if (S_ISBLK(file.st_mode))
		ft_putchar('b');
	else if (S_ISCHR(file.st_mode))
		ft_putchar('c');
	else if (S_ISDIR(file.st_mode))
		ft_putchar('d');
	else if (S_ISLNK(file.st_mode))
		ft_putchar('l');
	else if (S_ISSOCK(file.st_mode))
		ft_putchar('s');
	else if (S_ISFIFO(file.st_mode))
		ft_putchar('p');
	else
		ft_putchar('-');
}
