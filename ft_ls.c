/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/03 15:46:08 by fkoehler         ###   ########.fr       */
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

int		main(int ac, char **av)
{
	int		nb_path;
	t_flag	flag;

	init_flag_struct(&flag);
	if (!(nb_path = (read_args(ac, av, &flag))))
		return (-1);
	while (flag.path)
	{
		if (nb_path > 1)
			ft_printf("%s:\n", flag.path->p_name);
		read_path(&flag, flag.path->p_name);
		if (flag.path->next)
			ft_putchar('\n');
		flag.path = flag.path->next;
	}
	return (0);
}
