/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_time.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:28:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/09 14:26:36 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	time_order(char *s1, char *s2, struct stat *f1, struct stat *f2)
{
	long	diff;

	if ((diff = ((*f2).st_mtime - (*f1).st_mtime)) != 0)
		return (diff);
	if ((diff = ((*f2).st_mtimespec.tv_nsec - (*f1).st_mtimespec.tv_nsec)) != 0)
		return (diff);
	return (ft_strcmp(s1, s2));
}

long	rev_time_order(char *s1, char *s2, struct stat *f1, struct stat *f2)
{
	long	diff;

	if ((diff = ((*f1).st_mtime - (*f2).st_mtime)) != 0)
		return (diff);
	if ((diff = ((*f1).st_mtimespec.tv_nsec - (*f2).st_mtimespec.tv_nsec)) != 0)
		return (diff);
	return (-(ft_strcmp(s1, s2)));
}
