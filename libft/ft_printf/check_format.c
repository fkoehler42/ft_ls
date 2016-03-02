/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_format.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/11 15:13:21 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/10 16:22:18 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		check_struct(t_arg *arg)
{
	if ((arg->l + arg->ll + arg->h + arg->hh + arg->j + arg->z) > 1)
		return (-1);
	return (0);
}

int		check_arg(const char *format, int start)
{
	int		i;
	int		arg_len;
	char	*argument;
	t_arg	arg;

	i = start;
	arg_len = 0;
	while (format[i])
	{
		if (ft_strchr("sSpdDioOuUxXcC%", format[i]) != NULL)
		{
			argument = ft_strsub(format, start, i - start + 1);
			arg_len = ft_strlen(argument);
			init_struct(&arg);
			i = store_arg(argument, &arg);
			free(argument);
			if (i == -1)
				return (0);
			else
				return (arg_len);
		}
		i++;
	}
	return (0);
}

int		check_format(const char *format)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			j = check_arg(format, i);
			i += j;
		}
		else
			i++;
	}
	return (0);
}
