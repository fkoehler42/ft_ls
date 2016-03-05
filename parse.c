/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 11:41:30 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"
void	parse_arg(t_flag *flag, char *arg)
{
	struct	stat buf;

	if ((lstat(arg, &buf)) < 0)
	{
		ft_putstr_fd("ft_ls: ", 2);
		ft_putstr_fd(arg, 2);
		ft_putstr_fd(": ", 2);
		ft_putendl_fd(strerror(errno), 2);
	}
	else if (S_ISDIR(buf.st_mode))
		add_path(flag, arg);
	else
		add_file(flag, arg, "");
}

void	set_sorting_funct(t_flag *flag)
{
	if (flag->r && flag->t)
		flag->fptr = &rev_time_order;
	else if (flag->t)
		flag->fptr = &time_order;
	else if (flag->r)
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
	{
		print_files(flag);
		delete_files_list(flag);
	}
	else if (!nb_path)
	{
		add_path(flag, ".");
		nb_path++;
	}
	return (nb_path);
}
