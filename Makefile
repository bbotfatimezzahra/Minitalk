# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/21 04:51:53 by fbbot             #+#    #+#              #
#    Updated: 2024/05/27 19:24:55 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
UTILS := minitalk_utils.c
SERVER := server
CLIENT := client
BSERVER := server_bonus
BCLIENT := client_bonus


.PHONY : all bonus clean fclean re 

all : $(CLIENT) $(SERVER) 

$(SERVER) : server.c $(UTILS)
	gcc server.c  $(UTILS) -o $(SERVER)

$(CLIENT) : client.c $(UTILS)
	gcc client.c  $(UTILS) -o $(CLIENT)

bonus : $(BSERVER) $(BCLIENT)

$(BSERVER) : server_bonus.c $(UTILS)
	gcc server_bonus.c $(UTILS) -o $(BSERVER)

$(BCLIENT) : client_bonus.c $(UTILS)
	gcc client_bonus.c $(UTILS) -o $(BCLIENT)

clean :
	rm -rf $(SERVER) $(CLIENT) $(BSERVER) $(BCLIENT)


fclean : clean

re : fclean all
