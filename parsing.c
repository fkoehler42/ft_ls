/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 12:23:47 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_sorting_funct(t_flag *flag)
{
	if (flag->r)
		flag->fptr = &rev_lexicographical_order;
	else
		flag->fptr = &lexicographical_order;
}

int		set_flags(char *arg, t_flag *flag)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] == 'a')
			flag->a = 1;
		else if (arg[i] == 'l')
			flag->l = 1;
		else if (arg[i] == 'r')
			flag->r = 1;
		else if (arg[i] == 'R')
			flag->rec = 1;
		else if (arg[i] == 't')
			flag->t = 1;
		else
			return (0);
		i++;
	}
	set_sorting_funct(flag);
	return (i == 0 ? 0 : 1);
}
