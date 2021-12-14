# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:52:15 by dmontema          #+#    #+#              #
#    Updated: 2021/12/14 01:25:46 by dmontema         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER_NAME := server
CLIENT_NAME := client

CC := gcc
CFLAGS := -Wall -Wextra -Werror

SERVER_SRCS := server.c
CLIENT_SRCS := client.c

SERVER_OBJS := $(SERVER_SRCS:.c=.o)
CLIENT_OBJS := $(CLIENT_SRCS:.c=.o)

LIBS := libft.a

all: $(SERVER_NAME) $(CLIENT_NAME)
	@printf "\x1B[32mCompilation complete.\n\x1B[0m"

$(SERVER_NAME): $(LIBS) $(SERVER_OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(SERVER_OBJS) -o $(SERVER_NAME)
	@printf "Compiling server...\n"

$(CLIENT_NAME): $(LIBS) $(CLIENT_OBJS)
	@$(CC) $(CFLAGS) $(LIBS) $(CLIENT_OBJS) -o $(CLIENT_NAME)
	@printf "Compiling client...\n"

.c.o:	
	@$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	@rm -f $(SERVER_OBJS)
	@rm -f $(CLIENT_OBJS)
	@printf "OBJECTS REMOVED!\n"

fclean:	clean
	@rm -f $(SERVER_NAME)
	@rm -f $(CLIENT_NAME)
	@printf "EXECS REMOVED!\n"

re:	fclean all