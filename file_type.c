/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_type.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 18:54:06 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 17:39:25 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

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
