# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ahmcherk <ahmcherk@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/01/13 17:20:26 by ahmcherk          #+#    #+#              #
#    Updated: 2020/01/25 16:32:01 by ahmcherk         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_select
FLAG = -Wall -Werror -Wextra
SRC = main.c cursor.c term.c varset.c keys.c signal.c
OBJ = $(SRC:.c=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	make -C libft
	gcc $(FLAGS) -c $(SRC)
	gcc $(FLAGS) -o $(NAME) $(OBJ) ./libft/libft.a -ltermcap

clean :
	rm -rf $(OBJ)
	make clean -C libft
	
fclean : clean
	rm -rf $(NAME)
	make fclean -C libft

re : fclean all

