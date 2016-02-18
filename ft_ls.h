/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/02/18 17:04:17 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include <dirent.h>
# include <sys/stat.h>
# include <errno.h>
# include <stdio.h>

# define DEBUG printf("%s, %d\n", __FILE__, __LINE__)

typedef struct			s_flag
{
	int					a;
	int					l;
	int					r;
	int					rec;
	int					t;
}						t_flag;

typedef struct			s_path
{
	char				*p_name;
	struct s_file		*file;
	struct s_path		*next;
}						t_path;

typedef struct			s_file
{
	char				*f_name;
	char				*path;
	struct s_file		*next;
}						t_file;

int				set_flags(char *arg, t_flag *flag);
int				add_path(t_path **path, char *arg);
int				add_file(t_flag flag, t_path *path, char *file);
int				read_path(t_flag flag, t_path *path, char *path_name);
void			sort_file(t_flag flag, t_path *path, t_file *new);
void			lexicographical_order(t_path *path, t_file *new);
void			rev_lexicographical_order(t_path *path, t_file *new);
void			recursive_path(t_path *path);
int				insert_path(t_path **path, char *path_name);
void			print_files(t_path *path);
void			perror(const char *s);

#endif
