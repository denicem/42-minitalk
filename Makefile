# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:52:15 by dmontema          #+#    #+#              #
#    Updated: 2021/12/19 17:55:59 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME	:=	server
CLIENT_NAME	:=	client

CC	:=	gcc
CFLAGS	:=	-Wall -Wextra -Werror

SRC_DIR	:=	./src
SERVER_SRCS	:= $(SRC_DIR)/server.c
CLIENT_SRCS	:= $(SRC_DIR)/client.c
SERVER_SRCS_BONUS	:=	$(SRC_DIR)/server_bonus.c
CLIENT_SRCS_BONUS	:=	$(SRC_DIR)/client_bonus.c

SERVER_OBJS	:=	$(SERVER_SRCS:.c=.o)
CLIENT_OBJS	:=	$(CLIENT_SRCS:.c=.o)
SERVER_OBJS_BONUS	:= $(SERVER_SRCS_BONUS:.c=.o)
CLIENT_OBJS_BONUS	:= $(CLIENT_SRCS_BONUS:.c=.o)

LIBS	:=	libft.a 

all:	$(SERVER_NAME) $(CLIENT_NAME)
	
$(LIBS):	
	@make -C $(SRC_DIR)/Libft

$(SERVER_NAME): $(LIBS) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@printf "Compiling server...\n"
	@printf "\x1B[32mMINITALK server: Compilation complete.\n\x1B[0m"

$(CLIENT_NAME): $(LIBS) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@printf "Compiling client...\n"
	@printf "\x1B[32mMINITALK client: Compilation complete.\n\x1B[0m"

bonus:	$(LIBS) $(SERVER_OBJS_BONUS) $(CLIENT_OBJS_BONUS)
	@$(CC) $(CFLAGS) $(LIBS) $(SERVER_OBJS_BONUS) -o $(SERVER_NAME)
	@$(CC) $(CFLAGS) $(LIBS) $(CLIENT_OBJS_BONUS) -o $(CLIENT_NAME)

.c.o:	
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(SERVER_OBJS)
	@rm -f $(CLIENT_OBJS)
	@make -C $(SRC_DIR)/Libft clean
	@printf "OBJECTS REMOVED!\n"

fclean:	clean
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)
	@make -C $(SRC_DIR)/Libft fclean
	@printf "EXECS REMOVED!\n"

re:	fclean all