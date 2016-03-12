/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorized_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 09:49:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/12 17:29:33 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
#include <stdio.h>

void	print_files_colorized_raw(struct stat *file, char *f_name, int width)
{
	if (S_ISBLK((*file).st_mode))
		ft_printf("\033[0;34m""%-*s""\033[01;0m", width, f_name);
	else if (S_ISCHR((*file).st_mode))
		ft_printf("\033[0;32m""%-*s""\033[01;0m", width, f_name);
	else if (S_ISDIR((*file).st_mode))
		ft_printf("\033[01;36m""%-*s""\033[01;0m", width, f_name);
	else if (S_ISLNK((*file).st_mode))
		ft_printf("\033[0;35m""%-*s""\033[01;0m", width, f_name);
	else if (S_ISSOCK((*file).st_mode))
		ft_printf("\033[0;33m""%-*s""\033[01;0m", width, f_name);
	else if (S_ISFIFO((*file).st_mode))
		ft_printf("\033[0;31m""%-*s""\033[01;0m", width, f_name);
	else
		ft_printf("%-*s", width, f_name);
}

void	print_files_colorized(struct stat *file, char *f_name)
{
	if (S_ISBLK((*file).st_mode))
		ft_printf("\033[0;34m""%s""\033[01;0m", f_name);
	else if (S_ISCHR((*file).st_mode))
		ft_printf("\033[0;32m""%s""\033[01;0m", f_name);
	else if (S_ISDIR((*file).st_mode))
		ft_printf("\033[01;36m""%s""\033[01;0m", f_name);
	else if (S_ISLNK((*file).st_mode))
		ft_printf("\033[0;35m""%s""\033[01;0m", f_name);
	else if (S_ISSOCK((*file).st_mode))
		ft_printf("\033[0;33m""%s""\033[01;0m", f_name);
	else if (S_ISFIFO((*file).st_mode))
		ft_printf("\033[0;31m""%s""\033[01;0m", f_name);
	else
		ft_putstr(f_name);
}
