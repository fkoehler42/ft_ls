/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:28:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 14:38:02 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_order(char *s1, char *s2)
{
	struct	stat buf1;
	struct	stat buf2;
	long	diff;

	if (((stat(s1, &buf1)) < 0) || ((stat(s2, &buf2)) < 0))
		return (-1);
	if ((diff = (buf2.st_mtime - buf1.st_mtime)) != 0)
		return (diff);
	if ((diff = (buf2.st_mtimespec.tv_nsec - buf1.st_mtimespec.tv_nsec)) != 0)
		return (diff);
	return (ft_strcmp(s1, s2));
}

int		rev_time_order(char *s1, char *s2)
{
	struct	stat buf1;
	struct	stat buf2;
	long	diff;

	if (((stat(s1, &buf1)) < 0) || ((stat(s2, &buf2)) < 0))
		return (-1);
	if ((diff = (buf1.st_mtime - buf2.st_mtime)) != 0)
		return (diff);
	if ((diff = (buf1.st_mtimespec.tv_nsec - buf2.st_mtimespec.tv_nsec)) != 0)
		return (diff);
	return (ft_strcmp(s2, s1));
}
