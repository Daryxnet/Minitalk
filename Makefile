# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dagarmil <dagarmil@student.42barcelon      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/24 13:30:02 by dagarmil          #+#    #+#              #
#    Updated: 2024/10/24 13:30:06 by dagarmil         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SERVER = server2
CLIENT = client
CC = gcc
CFLAGS = -Wall -Wextra -Werror
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)Libftnew.a

SRCS_SERVER = server2.c
SRCS_CLIENT = client.c

OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

all: $(SERVER) $(CLIENT)

$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) Libft/Libftnew.a

$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) Libft/Libftnew.a

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
