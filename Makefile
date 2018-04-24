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

SRC = //file names created will go here

OFILES = *.o

all: $(NAME)

$(NAME):
	gcc -Wall -Wextra -Werror -c $(SRC)
	ar cr $(NAME) $(OFILES)

clean:
	/bin/rm -f $(OFILES)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
