/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raw_display.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 11:57:25 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/10 13:25:22 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

static	int	get_term_width(void)
{
	struct winsize w;

	if ((ioctl(STDOUT_FILENO, TIOCGWINSZ, &w)) < 0)
	{
		perror("ioctl error");
		return (-1);
	}
	return (w.ws_col);
}

int			print_files_in_raw(t_flag *flag)
{
	int		columns;
	int		files_col;
	t_file	*tmp1;
	t_file	*tmp2;

	if ((columns = (get_term_width())) < 0)
		return (-1);
	files_col = columns / flag->max_char_name;

}
