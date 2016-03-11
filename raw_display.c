/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:57:25 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 18:17:55 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static void	print_files_in_row1(t_flag *flag, t_file *tmp1,
			int files_lines, int files_col)
{
	int		i;
	int		j;
	t_file	*tmp2;

	i = files_col;
	j = 0;
	tmp2 = tmp1;
	flag->color ? print_files_colorized_raw(&tmp1->stat, tmp1->f_name,
	(flag->max_char_name + 1)) :
	ft_printf("%-*s", (flag->max_char_name + 1), tmp1->f_name);
	while (--i && tmp2)
	{
		j = files_lines;
		while (j-- && tmp2)
			tmp2 = tmp2->next;
		if (tmp2)
			flag->color ? print_files_colorized_raw(&tmp2->stat,
			tmp2->f_name, (flag->max_char_name + 1)) :
			ft_printf("%-*s", (flag->max_char_name + 1), tmp2->f_name);
	}
	ft_putchar('\n');
}

int			print_files_in_row(t_flag *flag)
{
	int		k;
	int		files_col;
	int		files_lines;
	t_file	*tmp1;

	k = 0;
	if (flag->term_width < 0)
		return (-1);
	if (!(files_col = flag->term_width / (flag->max_char_name + 1)))
	{
		print_files_no_row(flag);
		return (0);
	}
	files_lines = (flag->nb_files % files_col == 0) ? flag->nb_files / files_col
	: (flag->nb_files / files_col) + 1;
	tmp1 = flag->file;
	k = files_lines;
	while (k--)
	{
			print_files_in_row1(flag, tmp1, files_lines, files_col);
			tmp1 = tmp1->next;
	}
	return (0);
}
