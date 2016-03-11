# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fkoehler <fkoehler@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/03/09 09:46:03 by fkoehler          #+#    #+#              #
#    Updated: 2016/03/11 14:57:00 by fkoehler         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = add_file_infos.c \
colorized_display.c \
delete_list.c \
directory_size.c \
file_perms_and_attr.c \
file_size.c \
file_time.c \
file_type.c \
ft_ls.c \
handle.c \
parse_args.c \
parse_flags.c \
print.c \
raw_display.c \
recursive.c \
sort_lexico.c \
sort_main.c \
sort_off.c \
sort_size.c \
sort_time.c

NAME = ft_ls

FLAGS = -g -Wall -Werror -Wextra

LIBDIR = ./libft/

LIB = $(LIBDIR)libft.a

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(LIB) $(OBJ)
		gcc $(FLAGS) $(OBJ) -L$(LIBDIR) -lft -o $(NAME)

$(LIB):
	make -C $(LIBDIR)

%.o: %.c
	gcc $(FLAGS) -c $< -I $(LIBDIR)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
