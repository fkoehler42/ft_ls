/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/17 16:22:07 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

t_flag	*create_flag_struct(void)
{
	t_flag	*flag;

	if (!(flag = (t_flag *)malloc(sizeof(*flag))))
		return (NULL);
	flag->a = 0;
	flag->l = 0;
	flag->r = 0;
	flag->rec = 0;
	flag->t = 0;
	flag->path = NULL;
	return (flag);
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
	t_flag	*flag;

	flag = create_flag_struct();
	if (read_args(ac, av, flag) == 0)
		return (-1);
	while (flag->path)
	{
		read_path(flag);
		flag->path = flag->path->next;
	}
	return (0);
}
