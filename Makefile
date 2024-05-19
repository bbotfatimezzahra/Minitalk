CC := cc
CFLAGS := -Wall -Wextra -Werror
SERVER := server
CLIENT := client
BSERVER := server_bonus
BCLIENT := client_bonus


.PHONY : all bonus clean fclean re 

all : $(CLIENT) $(SERVER) 

$(SERVER) : server.c
	gcc server.c -o $(SERVER)

$(CLIENT) : client.c
	gcc client.c minitalk_utils.c -o $(CLIENT)

bonus : $(BSERVER) $(BCLIENT)

$(BSERVER) : server_bonus.c
	gcc server_bonus.c -o $(BSERVER)

$(BCLIENT) : client_bonus.c
	gcc client_bonus.c minitalk_utils.c -o $(BCLIENT)

clean :
	rm -rf $(SERVER) $(CLIENT) $(BSERVER) $(BCLIENT)


fclean : clean

re : fclean all
