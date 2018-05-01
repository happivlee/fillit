# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vlee <marvin@42.fr>                        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/04/23 18:18:05 by vlee              #+#    #+#              #
#    Updated: 2018/04/23 18:18:11 by vlee             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

LIBFT = libft/libft.a

SRC =	helpers.c \
		main.c \
		read.c \
		solve.c

OFILES = *.o

all: $(NAME)

$(NAME): $(LIBFT)
	gcc -Wall -Wextra -Werror -c $(SRC)
	gcc $(OFILES) $(LIBFT) -o $(NAME)

$(LIBFT):
	make -C libft

clean:
	/bin/rm -f $(OFILES)
	/bin/rm -f libft/$(OFILES)

fclean: clean
	/bin/rm -f $(NAME)
	/bin/rm -f $(LIBFT)

re: fclean all
