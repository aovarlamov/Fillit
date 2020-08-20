# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bdrinkin <bdrinkin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/12/09 01:45:57 by bdrinkin          #+#    #+#              #
#    Updated: 2019/12/15 17:05:03 by bdrinkin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

FLAG = -Wall -Wextra -Werror

LIB_FOLDER = libft/

SRC_F = src/

SRC = $(SRC_F)main.c $(SRC_F)change_cord.c $(SRC_F)check_shift.c \
$(SRC_F)go_to_list.c $(SRC_F)help_ft.c $(SRC_F)print_map.c \
$(SRC_F)write_tetra.c $(SRC_F)all_shifts.c

all: $(NAME)

lib_compile:
	make -C $(LIB_FOLDER)

$(NAME): lib_compile
	gcc $(FLAG) $(SRC) -o $(NAME) -L $(LIB_FOLDER) -lft
		
clean:
	make -C $(LIB_FOLDER) fclean

fclean: clean
	rm -f $(NAME)

re: fclean all
