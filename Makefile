# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jhenriqu <jhenriqu@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/12 11:26:37 by jhenriqu          #+#    #+#              #
#    Updated: 2021/01/08 14:12:44 by jhenriqu         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = printflibft.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror

SRCS = ft_printf.c

SRCS_bonus = 

INCLUDE = 

OBJ = ft_*.o

.PHONY: all
all:$(NAME)
$(NAME):
	make bonus -C ./libft
	cp libft/libft.a $(NAME)
	$(CC) -c $(CFLAGS) $(SRCS)
	ar -rcs $(NAME) $(OBJ)

clean:
	make clean -C ./libft
	rm -rf $(OBJ)
fclean: clean
	make clean -C ./libft
	rm -rf $(NAME)

re: fclean all
