/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_size.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/09 13:49:49 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/09 14:05:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

long	size_order(char *s1, char *s2, struct stat *f1, struct stat *f2)
{
	long	diff;

	if ((diff = ((*f2).st_size - (*f1).st_size)) != 0)
		return (diff);
	return (ft_strcmp(s1, s2));
}

long	rev_size_order(char *s1, char *s2, struct stat *f1, struct stat *f2)
{
	long	diff;

	if ((diff = ((*f1).st_size - (*f2).st_size)) != 0)
		return (diff);
	return (-(ft_strcmp(s1, s2)));
}
