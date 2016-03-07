/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 11:00:34 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_sorting_funct(t_flag *flag)
{
	flag->fptr1 = NULL;
	flag->fptr2 = NULL;
	if (flag->r && flag->t)
		flag->fptr2 = &rev_time_order;
	else if (flag->t)
		flag->fptr2 = &time_order;
	else if (flag->r)
		flag->fptr1 = &rev_lexico_order;
	else
		flag->fptr1 = &lexico_order;
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
			flag_error(arg[i]);
		i++;
	}
	if (flag->r || flag->t)
		set_sorting_funct(flag);
	return (i == 0 ? 0 : 1);
}

void	flag_error(int c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-alrRt] [file ...]\n", 2);
	exit(EXIT_SUCCESS);
}
