# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: oipadeol <oipadeol@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/09 14:40:34 by oipadeol          #+#    #+#              #
#    Updated: 2021/10/19 19:21:39 by oipadeol         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libftprintf.a

SRC =	ft_printf.c ft_writep_utils.c flag_format.c\
		flag_set.c ft_write_all.c

FLAGS =	-Wall -Wextra -Werror

SUB_DIR = libft

all: $(NAME)

$(NAME): lib

bonus: lib
	ar -cr libftprintf_bonus.a *.o $(SUB_DIR)/*.o

sub_lib:
	cd $(SUB_DIR) && $(MAKE)

lib: objects sub_lib
	ar -cr $(NAME) *.o $(SUB_DIR)/*.o

objects:
	gcc -c $(FLAGS) $(SRC)
	
clean: libftclean
	rm -f *.o

libftclean:
	cd libft && $(MAKE) clean

fclean: clean libftfclean
	rm -f $(NAME)
	rm -f libftprintf_bonus.a

libftfclean: 
	cd libft && $(MAKE) fclean

re: fclean all
