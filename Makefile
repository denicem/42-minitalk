# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dmontema <dmontema@42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/10 19:52:15 by dmontema          #+#    #+#              #
#    Updated: 2021/12/10 20:09:17 by dmontema         ###   ########.fr        #
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

$(SERVER_NAME): $(LIBS) $(SERVER_OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(SERVER_OBJS) -o $(SERVER_NAME)

$(CLIENT_NAME): $(LIBS) $(CLIENT_OBJS)
	$(CC) $(CFLAGS) $(LIBS) $(CLIENT_OBJS) -o $(CLIENT_NAME)

.c.o:	
	$(CC) $(CFLAGS) -c $< -o $(<:.c=.o)

clean:
	rm -f $(SERVER_OBJS)
	rm -f $(CLIENT_OBJS)

fclean:	clean
	rm -f $(SERVER_NAME)
	rm -f $(CLIENT_NAME)

re:	fclean all