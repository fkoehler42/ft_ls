/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/28 14:33:46 by fkoehler          #+#    #+#             */
/*   Updated: 2016/01/28 14:37:23 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
}
