/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/13 17:39:09 by fkoehler         ###   ########.fr       */
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

int		read_args(char **args, int n)
{
	int		i;
	int		path;
	t_flags	flags;
	t_path	*path;

	i = 0;
	path = 0;
	init_flags(&flags);
	while (i < n)
	{
		if (args[i][0] != '-' && ++path)
			path = set_path(arg[i]);
		else if (args[i][0] == '-' && !path)
			set_flags(args[i] + 1, &flags);
		else
			return (0);
		i++;
	}
	return (1);
}

int		main(int ac, char **av)
{
	read_args(av, ac);
	return (0);
}
