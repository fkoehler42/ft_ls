/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/02 10:56:59 by fkoehler         ###   ########.fr       */
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
	int					(*fptr)(char *, char *);
	struct s_path		*path;
	struct s_file		*file;
}						t_flag;

typedef struct			s_path
{
	char				*p_name;
	struct s_path		*next;
}						t_path;

typedef struct			s_file
{
	char				*f_name;
	char				*f_path;
	struct s_file		*next;
}						t_file;

int				set_flags(char *arg, t_flag *flag);
int				add_path(t_flag *flag, char *arg);
int				add_file(t_flag *flag, char *file, char *path_name);
int				read_path(t_flag *flag, char *path_name);
void			set_sorting_funct(t_flag *flag);
void			sort_file(t_flag *flag, t_file *new);
void			sort_path(t_flag *flag, t_path *new);
int				lexicographical_order(char *s1, char *s2);
int				rev_lexicographical_order(char *s1, char *s2);
void			recursive_path(t_flag *flag);
void			print_files(t_flag *flag, char *path_name);
void			delete_files_list(t_flag *flag);
void			perror(const char *s);

#endif
