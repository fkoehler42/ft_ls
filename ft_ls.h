/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/15 16:03:26 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>

# define DEBUG printf("%s, %d\n", __FILE__, __LINE__)

typedef struct			s_flags
{
	int					a;
	int					l;
	int					r;
	int					rec;
	int					t;
}						t_flags;

typedef struct			s_path
{
	char				*path;
	struct s_path		*next;
}						t_path;

int				set_flags(char *arg, t_flags *flags);
int				set_path(t_path **path, char *arg);
int				open_path(t_path *path);
void			perror(const char *s);

#endif
