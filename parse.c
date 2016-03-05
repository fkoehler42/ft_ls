/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 20:55:09 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
void	parse_arg(t_flag *flag, char *arg)
{
	struct stat buf;

	if ((lstat(arg, &buf)) < 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		perror(arg);
	}
	else if (S_ISDIR(buf.st_mode))
		add_path(flag, arg);
	else if (S_ISLNK(buf.st_mode))
	{
		if ((stat(arg, &buf)) < 0)
			add_file(flag, arg, "");
		else
			add_path(flag, arg);
	}
	else
		add_file(flag, arg, "");
}

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
			return (0);
		i++;
	}
	if (flag->r || flag->t)
		set_sorting_funct(flag);
	return (i == 0 ? 0 : 1);
}

int		read_args(int ac, char **av, t_flag *flag)
{
	int		i;
	int		nb_path;

	i = 1;
	nb_path = 0;
	while (i < ac)
	{
		if (av[i][0] == '-' && nb_path == 0)
			set_flags(av[i] + 1, flag);
		else if (av[i][0] != '-' && ++nb_path)
			parse_arg(flag, av[i]);
		else
			return (0);
		i++;
	}
	if (flag->file)
		print_files(flag);
	else if (!nb_path)
	{
		add_path(flag, ".");
		nb_path++;
	}
	return (nb_path);
}
