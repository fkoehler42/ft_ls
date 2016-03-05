/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_owner.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/03 16:06:43 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 21:35:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_user_and_group(struct stat *file)
{
	struct	passwd *user;
	struct	group *group;

	user = getpwuid((*file).st_uid);
	group = getgrgid((*file).st_gid);
	if (user->pw_name)
		ft_printf("%-10s", user->pw_name);
	else
		ft_printf("%-10d", file->st_uid);
	if (group->gr_name)
		ft_printf("%-10s", group->gr_name);
	else
		ft_printf("%-10d", file->st_gid);
}
