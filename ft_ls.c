/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 12:22:19 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

void	init_flag_struct(t_flag *flag)
{
	flag->a = 0;
	flag->l = 0;
	flag->r = 0;
	flag->rec = 0;
	flag->t = 0;
	flag->fptr = &lexicographical_order;
	flag->path = NULL;
	flag->file = NULL;
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
			add_path(flag, av[i]);
		else
			return (0);
		i++;
	}
	if (!(nb_path))
		add_path(flag, ".");
	return (1);
}

int		main(int ac, char **av)
{
	t_flag	flag;

	init_flag_struct(&flag);
	if (!(read_args(ac, av, &flag)))
		return (-1);
	while (flag.path)
	{
		read_path(&flag, flag.path->p_name);
		flag.path = flag.path->next;
	}
	return (0);
}
