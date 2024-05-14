# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbbot <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/03/04 22:35:06 by fbbot             #+#    #+#              #
#    Updated: 2024/03/31 07:47:39 by fbbot            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC := cc
CFLAGS := -Wall -Wextra -Werror
SRCS := checkfunc.c headerfunc.c lstfunc.c fill_stack.c indexfunc.c\
OBJS := $(SRCS:%.c=%.o)
LIB := minitalk.a
SERVER := server
CLIENT := client

.PHONY : all bonus clean fclean re 

.SECONDARY : $(OBJS)

all : $(CLIENT) $(SERVER) 

$(LIB) : $(OBJS)
	ar rc $(LIB) $(OBJS)

$(SERVER) : $(LIB) server.c
	gcc server.c -o $(SERVER) $(LIB)

$(CLIENT) : $(LIB) client.c
	gcc client.c -o $(CLIENT) $(LIB)

bonus : all 

clean :
	rm -rf $(OBJS)

fclean : clean
	rm -rf $(LIB) $(CLIENT) $(SERVER)

re : fclean all
