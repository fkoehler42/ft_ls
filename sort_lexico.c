/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_lexico.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/17 16:30:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 22:34:24 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_ls.h"

int		lexico_order(char *s1, char *s2)
{
	return (ft_strcmp(s1, s2));
}

int		rev_lexico_order(char *s1, char *s2)
{
	return (-(ft_strcmp(s1, s2)));
}
