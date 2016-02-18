/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 19:22:00 by fkoehler         ###   ########.fr       */
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
}

t_path	*read_args(int ac, char **av, t_flag *flag)
{
	int		i;
	int		nb_path;
	t_path	*path;

	i = 1;
	nb_path = 0;
	path = NULL;
	while (i < ac)
	{
		if (av[i][0] == '-' && nb_path == 0)
			set_flags(av[i] + 1, flag);
		else if (av[i][0] != '-' && ++nb_path)
			add_path(*flag, &path, av[i]);
		else
			return (NULL);
		i++;
	}
	if (!(nb_path))
		add_path(*flag, &path, ".");
	return (path);
}

int		main(int ac, char **av)
{
	t_flag	flag;
	t_path *path;

	init_flag_struct(&flag);
	if (!(path = read_args(ac, av, &flag)))
		return (-1);
	while (path)
	{
		read_path(flag, path, path->p_name);
		path = path->next;
	}
	return (0);
}
