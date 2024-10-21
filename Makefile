SOURCES = server.c client.c
OBJECTS = $(SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror

all: server client

bonus: server client

server: server.o libft
	$(CC) -o $@ $< -Llibft -lft

client: client.o libft
	$(CC) -o $@ $< -Llibft -lft

%.o: %.c
	$(CC) -c $(CFLAGS) $?

libft:
	make -C Libft

clean:
	rm -f $(OBJECTS)
	make -C Libft clean
	
fclean: clean
	rm -f server client Libft/libft/libft.a

re: fclean all

.PHONY: all bonus libft clean fclean re
