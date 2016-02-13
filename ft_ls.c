/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/13 18:47:56 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_flags(t_flags *flags)
{
	flags->a = 0;
	flags->l = 0;
	flags->r = 0;
	flags->R = 0;
	flags->t = 0;
}

int		read_args(int ac, char **av)
{
	int		i;
	int		nb_path;
	t_flags	flags;
	t_path	*path;

	i = 1;
	nb_path = 0;
	path = NULL;
	init_flags(&flags);
	while (i < ac)
	{
		if (av[i][0] != '-' && ++nb_path)
			path = set_path(path, av[i]);
		else if (av[i][0] == '-' && nb_path == 0)
			set_flags(av[i] + 1, &flags);
		else
			return (0);
		i++;
	}
	ft_putstr(path->path);
	ft_putnbr(flags.a);
	ft_putnbr(flags.l);
	ft_putnbr(flags.r);
	ft_putnbr(flags.R);
	ft_putnbr(flags.t);
	return (1);
}

int		main(int ac, char **av)
{
	read_args(ac, av);
	return (0);
}
