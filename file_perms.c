/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_perms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 11:37:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 12:33:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_owner_perms(struct stat file)
{
	if (file.st_mode & S_IXUSR)
		ft_putstr("rwx");
	else if (file.st_mode & 600)
		ft_putstr("rw-");
	else if (file.st_mode & 500)
		ft_putstr("r-x");
	else if (file.st_mode & 400)
		ft_putstr("r--");
	else if (file.st_mode & 300)
		ft_putstr("-wx");
	else if (file.st_mode & 200)
		ft_putstr("-w-");
	else if (file.st_mode & 100)
		ft_putstr("--x");

}
