/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/07 18:36:16 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 20:54:59 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	print_file_size(t_flag *flag, struct stat *file)
{
	long	maj;
	long	min;

	maj = 0;
	min = 0;
	if ((S_ISBLK((*file).st_mode)) || (S_ISCHR((*file).st_mode)))
	{
		maj = major(file->st_rdev);
		min = minor(file->st_rdev);
		ft_printf("%*ld,%*ld ", (flag->max_char_dev + 1), maj,
		flag->max_char_size + 1,min);
	}
	else
		ft_printf("%*d ", (flag->max_char_size + flag->max_char_dev + 3),
		file->st_size);
}
