/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/09 12:08:21 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	set_sorting_funct(t_flag *flag)
{
	flag->fptr1 = NULL;
	flag->fptr2 = NULL;
	if (flag->f)
		return ;
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
	while (*arg)
	{
		if (*arg == 'a')
			flag->a = 1;
		else if (*arg == 'l' && (flag->g == 0))
			flag->l = 1;
		else if (*arg == 'r' && (flag->f == 0))
			flag->r = 1;
		else if (*arg == 'R')
			flag->rec = 1;
		else if (*arg == 't' && (flag->f == 0))
			flag->t = 1;
		else if (*arg == '1')
			flag->l = 0;
		else if (*arg == 'f')
			flag->f = 1;
		else if (*arg == 'g')
		{
			flag->g = 1;
			flag->l = 0;
		}
		else if ((*arg != 'r') && (*arg != 't') && (*arg != 'l'))
			flag_error(*arg);
		arg++;
	}
	if (flag->r || flag->t || flag->f)
		set_sorting_funct(flag);
	return (0);
}

void	flag_error(int c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-afglrRt1] [file ...]\n", 2);
	exit(EXIT_SUCCESS);
}
