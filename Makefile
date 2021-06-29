# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: sel-fcht <sel-fcht@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/06/11 18:17:56 by sel-fcht          #+#    #+#              #
#    Updated: 2021/06/12 21:07:36 by sel-fcht         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC1 = client.c bonus.c
SRC2 = server.c bonus.c
FLGS = -Wall -Werror -Wextra
NAME = server client
PRINT = @echo  "\0033[0;32m ----> CREATING THE SERVER AND THE CLIENT EXECUTABLE <---- "
PRINT2 = @echo "\0033[0;31m ----> REMOVING THE CLIENT AND SERVER EXECUTABLE <----"
all : $(NAME)
$(NAME): $(SRC1) $(SRC2) 
	$(PRINT)
	gcc $(FLGS) -o server $(SRC2)
	gcc $(FLGS) -o client $(SRC1)

clean:
	rm -rf *.o
	
fclean: clean
		$(PRINT2)
		rm -f server
		rm -f client

re: fclean all
