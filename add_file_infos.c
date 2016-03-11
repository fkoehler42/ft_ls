/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_file_infos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 16:21:03 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 14:28:50 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static int	count_char(long nb)
{
	int	i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb = nb / 10;
		i++;
	}
	return (i);
}

static void	set_user_and_group(t_file *file)
{
	t_passwd	*user;
	t_group		*group;

	user = getpwuid(file->stat.st_uid);
	group = getgrgid(file->stat.st_gid);
	if (user != NULL)
		file->owner = ft_strdup(user->pw_name);
	else
		file->owner = ft_itoa(file->stat.st_uid);
	if (group != NULL)
		file->group = ft_strdup(group->gr_name);
	else
		file->group = ft_itoa(file->stat.st_gid);
}

static void	device_infos(t_flag *flag, t_file *file)
{
	int	nb_char;

	nb_char = 0;
	if ((nb_char = count_char(major(file->stat.st_rdev))) > flag->max_char_dev)
		flag->max_char_dev = nb_char;
	if ((nb_char = count_char(minor(file->stat.st_rdev))) > flag->max_char_size)
		flag->max_char_size = nb_char;
}

int			add_file_infos(t_flag *flag, t_file *file)
{
	int	nb_char;

	nb_char = 0;
	if (lstat(file->f_path, &file->stat) < 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(file->f_name);
	}
	if ((nb_char = (ft_strlen(file->f_name))) > flag->max_char_name)
		flag->max_char_name = nb_char;
	if ((nb_char = (count_char(file->stat.st_nlink))) > flag->max_char_link)
		flag->max_char_link = nb_char;
	set_user_and_group(file);
	if ((nb_char = (ft_strlen(file->owner))) > flag->max_char_owner)
		flag->max_char_owner = nb_char;
	if ((nb_char = (ft_strlen(file->group))) > flag->max_char_group)
		flag->max_char_group = nb_char;
	if ((S_ISBLK(file->stat.st_mode)) || (S_ISCHR(file->stat.st_mode)))
		device_infos(flag, file);
	else if ((nb_char = (count_char(file->stat.st_size))) > flag->max_char_size)
		flag->max_char_size = nb_char;
	return (0);
}
