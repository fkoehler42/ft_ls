/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/02/13 14:15:32 by fkoehler          #+#    #+#             */
/*   Updated: 2016/03/11 14:30:28 by fkoehler         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# define BLUE "\033[0;34m"
# define GREEN "\033[0;32m"
# define RED "\033[0;31m"
# define PURPLE	"\033[0;35m"
# define YELLOW "\033[1;33m"
# define CYAN "\033[1;36m"
# define OFF "\033[01;0m"

# include "libft/includes/libft.h"
# include "libft/includes/ft_printf.h"
# include <stdio.h>
# include <dirent.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/xattr.h>
# include <sys/acl.h>
# include <sys/ioctl.h>
# include <pwd.h>
# include <grp.h>
# include <time.h>

typedef struct group	t_group;
typedef struct passwd	t_passwd;
typedef struct			s_flag
{
	int					a;
	int					f;
	int					g;
	int					l;
	int					r;
	int					rec;
	int					s;
	int					t;
	int					one;
	int					color;
	int					nb_files;
	int					max_char_name;
	int					max_char_link;
	int					max_char_owner;
	int					max_char_group;
	int					max_char_size;
	int					max_char_dev;
	int					(*fptr1)(char *, char *);
	long				(*fptr2)(char *, char *, struct stat *, struct stat *);
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
	char				*owner;
	char				*group;
	struct stat			stat;
	struct s_file		*next;
}						t_file;

int				read_args(int ac, char **av, t_flag *flag);
void			parse_arg(t_flag *flag, char *arg);
int				set_flags(char *arg, t_flag *flag);
void			flag_error(int c);
int				add_path(t_flag *flag, char *arg);
int				add_file(t_flag *flag, char *file, char *path_name);
int				add_file_infos(t_flag *flag, t_file *file);
int				read_path(t_flag *flag, char *path_name);

void			set_sorting_funct(t_flag *flag);
void			sort_file1(t_flag *flag, t_file *new);
void			sort_file2(t_flag *flag, t_file *new);
void			sort_path1(t_flag *flag, t_path *new);
void			sort_path2(t_flag *flag, t_path *new);
void			no_sorting_file(t_flag *flag, t_file *new);
void			no_sorting_path(t_flag *flag, t_path *new);
int				lexico_order(char *s1, char *s2);
int				rev_lexico_order(char *s1, char *s2);
long			size_order(char *s1, char *s2,
				struct stat *f1, struct stat *f2);
long			rev_size_order(char *s1, char *s2,
				struct stat *f1, struct stat *f2);
long			time_order(char *s1, char *s2,
				struct stat *f1, struct stat *f2);
long			rev_time_order(char *s1, char *s2,
				struct stat *f1, struct stat *f2);
void			recursive_path(t_flag *flag);

void			delete_files_list(t_flag *flag);
void			delete_paths_list(t_flag *flag);
void			reset_field_widths(t_flag *flag);

int				count_blocks(t_flag *flag);
void			print_files(t_flag *flag);
void			print_files_colorized(struct stat *file, char *f_name);
void			print_files_colorized_raw(struct stat *file, char *f_name,
				int width);
int				print_files_in_row(t_flag *flag);
void			print_files_no_row(t_flag *flag);
void			print_files_infos(t_flag *flag, t_file *file);
void			print_file_type(struct stat *file);
int				print_file_attr(t_file *file);
void			print_file_size(t_flag *flag, struct stat *file);
void			print_file_time(struct stat *file);
void			print_symlink(t_flag *flag, t_file *file);
void			set_owner_and_group_perms(struct stat *file, char *perms);
void			set_other_perms(struct stat *file, char *perms);


#endif
