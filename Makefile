# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: twoerdem <twoerdem@student.codam.nl>         +#+                      #
#                                                    +#+                       #
#    Created: 2019/06/27 16:01:54 by twoerdem       #+#    #+#                 #
#    Updated: 2019/08/28 16:23:10 by twoerdem      ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

NAME = twoerdem.filler
SRC = src/main.c src/read.c src/utility.c src/filler.c
LIBFT = -L./libft -lft
FLAGS = -Wall -Werror -Wextra

all: $(NAME)

re: fclean all

$(NAME):
	@make -C libft/ fclean && make -C libft/
	@gcc -o $(NAME) $(FLAGS) $(SRC) $(LIBFT)

clean:
	cd libft && make clean

fclean: clean
	cd libft && make fclean
	rm -f $(NAME)
