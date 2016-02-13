/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/13 18:15:57 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>

typedef struct			s_flags
{
	int					a;
	int					l;
	int					r;
	int					R;
	int					t;
}						t_flags;

typedef struct			s_path
{
	char				*path;
	struct s_path		*next;
}						t_path;

int				set_flags(char *arg, t_flags *flags);
t_path			*set_path(t_path *path, char *arg);


#endif
