/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 15:13:34 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/07 17:07:52 by fkoehler         ###   ########.fr       */
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
	flag->max_char_link = 0;
	flag->max_char_owner = 0;
	flag->max_char_group = 0;
	flag->max_char_size = 0;
	flag->fptr1 = &lexico_order;
	flag->fptr2 = NULL;
	flag->path = NULL;
	flag->file = NULL;
}

int		main(int ac, char **av)
{
	int		nb_path;
	t_flag	flag;
	t_path	*tmp;

	init_flag_struct(&flag);
	nb_path = read_args(ac, av, &flag);
	tmp = flag.path;
	while (tmp)
	{
		if (nb_path > 1 && flag.file)
		{
			delete_files_list(&flag);
			ft_printf("\n%s:\n", tmp->p_name);
		}
		else if (nb_path > 1)
			ft_printf("%s:\n", tmp->p_name);
		read_path(&flag, tmp->p_name);
		tmp = tmp->next;
		if (tmp)
			ft_putchar('\n');
	}
	delete_paths_list(&flag);
	return (0);
}
