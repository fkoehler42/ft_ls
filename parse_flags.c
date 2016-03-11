/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 12:04:05 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void			set_sorting_funct(t_flag *flag)
{
	flag->fptr1 = NULL;
	flag->fptr2 = NULL;
	if (flag->f)
		return ;
	if (flag->r && flag->s)
		flag->fptr2 = &rev_size_order;
	else if (flag->s)
		flag->fptr2 = &size_order;
	else if (flag->r && flag->t)
		flag->fptr2 = &rev_time_order;
	else if (flag->t)
		flag->fptr2 = &time_order;
	else if (flag->r)
		flag->fptr1 = &rev_lexico_order;
	else
		flag->fptr1 = &lexico_order;
}

static	void	set_flags1(char *arg, t_flag *flag)
{
	if (*arg == 't' && (flag->f == 0) && (flag->s == 0))
		flag->t = 1;
	else if (*arg == '1')
	{
		flag->l = 0;
		flag->g = 0;
		flag->one = 1;
	}
	else if (*arg == 'f')
	{
		flag->f = 1;
		flag->s = 0;
		flag->t = 0;
	}
	else if (*arg == 'g')
	{
		flag->g = 1;
		flag->l = 0;
		flag->one = 0;
	}
	else if (*arg == 'S' && (flag->f == 0))
		flag->s = 1;
	else if ((*arg != 'r') && (*arg != 't') && (*arg != 'l'))
		flag_error(*arg);
}

int				set_flags(char *arg, t_flag *flag)
{
	while (*arg)
	{
		if (*arg == 'a')
			flag->a = 1;
		else if (*arg == 'G')
			flag->color = 1;
		else if (*arg == 'R')
			flag->rec = 1;
		else if (*arg == 'l' && (flag->g == 0))
		{
			flag->l = 1;
			flag->one = 0;
		}
		else if (*arg == 'r' && (flag->f == 0))
			flag->r = 1;
		else
			set_flags1(arg, flag);
		arg++;
	}
	if (flag->r || flag->t || flag->f || flag->s)
		set_sorting_funct(flag);
	return (0);
}

void			flag_error(int c)
{
	ft_putstr_fd("ft_ls: illegal option -- ", 2);
	ft_putchar_fd(c, 2);
	ft_putstr_fd("\nusage: ft_ls [-afgGlrRSt1] [file ...]\n", 2);
	exit(EXIT_SUCCESS);
}
