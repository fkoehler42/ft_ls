/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_perms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:37:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 15:52:06 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_owner_perms(struct stat file)
{
	(file.st_mode & S_IRUSR) ? ft_putchar('r') : ft_putchar('-');
	(file.st_mode & S_IWUSR) ? ft_putchar('w') : ft_putchar('-');
	if (file.st_mode & S_IXUSR & S_ISUID)
		ft_putchar('s');
	else if (file.st_mode & S_ISUID)
		ft_putchar('S');
	else if (file.st_mode & S_IXUSR)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_group_perms(struct stat file)
{
	(file.st_mode & S_IRGRP) ? ft_putchar('r') : ft_putchar('-');
	(file.st_mode & S_IWGRP) ? ft_putchar('w') : ft_putchar('-');
	if ((file.st_mode & S_IXGRP) && (file.st_mode & S_ISGID))
		ft_putchar('s');
	else if (file.st_mode & S_ISGID)
		ft_putchar('S');
	else if (file.st_mode & S_IXGRP)
		ft_putchar('x');
	else
		ft_putchar('-');
}

void	print_other_perms(struct stat file)
{
	(file.st_mode & S_IROTH) ? ft_putchar('r') : ft_putchar('-');
	(file.st_mode & S_IWOTH) ? ft_putchar('w') : ft_putchar('-');
	if ((file.st_mode & S_IXOTH) && (file.st_mode & S_ISVTX))
		ft_putchar('t');
	else if (file.st_mode & S_ISVTX)
		ft_putchar('T');
	else if (file.st_mode & S_IXOTH)
		ft_putchar('x');
	else
		ft_putchar('-');

}
