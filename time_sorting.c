/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_sorting.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/02 12:28:20 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 12:46:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		time_order(char *s1, char *s2)
{
	struct	stat buf1;
	struct	stat buf2;

	if (((stat(s1, &buf1)) < 0) || ((stat(s2, &buf2)) < 0))
		return (-1);
	return (ft_strcmp())
}
