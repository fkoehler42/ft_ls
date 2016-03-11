/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorized_display.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/11 09:49:31 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 10:11:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_files_colorized_raw(struct stat *file, char *f_name, int width)
{
	if (S_ISBLK((*file).st_mode))
		ft_printf(BLUE"%-*s"OFF, width, f_name);
	else if (S_ISCHR((*file).st_mode))
		ft_printf(GREEN"%-*s"OFF, width, f_name);
	else if (S_ISDIR((*file).st_mode))
		ft_printf(CYAN"%-*s"OFF, width, f_name);
	else if (S_ISLNK((*file).st_mode))
		ft_printf(PURPLE"%-*s"OFF, width, f_name);
	else if (S_ISSOCK((*file).st_mode))
		ft_printf(YELLOW"%-*s"OFF, width, f_name);
	else if (S_ISFIFO((*file).st_mode))
		ft_printf(RED"%-*s"OFF, width, f_name);
	else
		ft_printf("%-*s", width, f_name);
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
