/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_percent.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/01 10:46:28 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/10 15:52:53 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	print_percent(t_arg *arg)
{
	if (arg->minus && arg->width > 1)
	{
		ft_putchar('%');
		ft_putnspaces(arg->width - 1);
		g_bytes += arg->width;
	}
	else if (arg->width > 1)
	{
		arg->zero ? ft_putnzeros(arg->width - 1) :
		ft_putnspaces(arg->width - 1);
		ft_putchar('%');
		g_bytes += arg->width;
	}
	else
	{
		ft_putchar('%');
		g_bytes++;
	}
}
