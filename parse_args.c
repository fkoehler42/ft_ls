/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 17:22:10 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 12:43:11 by fkoehler         ###   ########.fr       */
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
		if ((stat(arg, &buf)) < 0 || flag->l)
			add_file(flag, arg, "");
		else
			add_path(flag, arg);
	}
	else
		add_file(flag, arg, "");
}

int		read_args(int ac, char **av, t_flag *flag)
{
	int		i;
	int		nb_path;

	i = 1;
	nb_path = 0;
	while (i < ac)
	{
		if (!(nb_path == 0 && (ft_strcmp(av[i], "--") == 0)))
		{
			if (av[i][0] == '-' && av[i][1] && nb_path == 0
				&& (ft_strcmp(av[1], "--") != 0))
				set_flags(av[i] + 1, flag);
			else if (++nb_path)
				parse_arg(flag, av[i]);
		}
		i++;
	}
	if (flag->file)
		print_files(flag);
	else if ((!nb_path) && ++nb_path)
		add_path(flag, ".");
	return (nb_path);
}
