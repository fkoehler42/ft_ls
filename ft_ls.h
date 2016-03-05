/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/05 17:22:08 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <dirent.h>
# include <sys/stat.h>
//# include <sys/types.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>
//# include <errno.h>

# define DEBUG ft_printf("%s, %d\n", __FILE__, __LINE__)

typedef struct			s_flag
{
	int					a;
	int					l;
	int					r;
	int					rec;
	int					t;
	int					(*fptr)(char *, char *, struct stat, struct stat);
	struct s_path		*path;
	struct s_file		*file;
}						t_flag;

typedef struct			s_path
{
	char				*p_name;
	struct stat			stat;
	struct s_path		*next;
}						t_path;

typedef struct			s_file
{
	char				*f_name;
	char				*f_path;
	struct stat			stat;
	struct s_file		*next;
}						t_file;

void			perror(const char *s);
int				read_args(int ac, char **av, t_flag *flag);
void			parse_arg(t_flag *flag, char *arg);
int				set_flags(char *arg, t_flag *flag);
int				add_path(t_flag *flag, char *arg);
int				add_file(t_flag *flag, char *file, char *path_name);
int				read_path(t_flag *flag, char *path_name);
void			set_sorting_funct(t_flag *flag);
void			sort_file(t_flag *flag, t_file *new);
void			sort_path(t_flag *flag, t_path *new);
int				lexico_order(char *s1, char *s2, struct stat f1, struct stat f2);
int				rev_lexico_order(char *s1, char *s2, struct stat f1, struct stat f2);
int				time_order(char *s1, char *s2, struct stat f1, struct stat f2);
int				rev_time_order(char *s1, char *s2, struct stat f1, struct stat f2);
void			recursive_path(t_flag *flag);
void			delete_files_list(t_flag *flag);
void			delete_paths_list(t_flag *flag);

int				count_blocks(t_flag *flag);
void			print_files(t_flag *flag);
void			print_files_infos(t_file *file);
void			print_file_type(struct stat file);
void			print_file_time(struct stat file);
void			print_owner_perms(struct stat file);
void			print_group_perms(struct stat file);
void			print_other_perms(struct stat file);
void			print_user_and_group(struct stat file);

#endif
