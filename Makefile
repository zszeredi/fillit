# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lhenneca <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/27 16:23:28 by lhenneca          #+#    #+#              #
#    Updated: 2020/02/27 16:23:32 by lhenneca         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit
FLAGS = -Wall -Wextra -Werror
C_FILES = 	 main.c\
			 backtracking.c\
			 check_charachters.c\
			 create_table.c\
			 delete_table.c\
			 printing.c\
			 read_file.c\
			 save_cordis.c\
			 storage.c\


all: $(NAME) 

$(NAME): getlibft
	gcc $(FLAGS) $(C_FILES) libft/libft.a -o $(NAME)

getlibft:
	make -C libft

clean:
	/bin/rm -f *.o
	/bin/rm -f libft/*.o

fclean: clean
	/bin/rm -f $(NAME) libft.a
	/bin/rm -f libft/libft.a

re: fclean all
