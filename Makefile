# Nombre del ejecutable
SERVER = server
CLIENT = client

# Compilador y banderas
CC = gcc
CFLAGS = -Wall -Wextra -Werror

# Directorios
LIBFT_DIR = Libft/
LIBFT = $(LIBFT_DIR)Libftnew.a

# Archivos fuente
SRCS_SERVER = server.c
SRCS_CLIENT = client.c

# Archivos objeto
OBJS_SERVER = $(SRCS_SERVER:.c=.o)
OBJS_CLIENT = $(SRCS_CLIENT:.c=.o)

# Reglas para todo
all: $(SERVER) $(CLIENT)

# Compilar el servidor
$(SERVER): $(OBJS_SERVER) $(LIBFT)
	$(CC) $(CFLAGS) -o $(SERVER) $(OBJS_SERVER) Libft/Libftnew.a

# Compilar el cliente
$(CLIENT): $(OBJS_CLIENT) $(LIBFT)
	$(CC) $(CFLAGS) -o $(CLIENT) $(OBJS_CLIENT) Libft/Libftnew.a

# Compilar la libft si no existe
$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR)

# Limpiar objetos
clean:
	$(MAKE) -C $(LIBFT_DIR) clean
	rm -f $(OBJS_SERVER) $(OBJS_CLIENT)

# Limpiar todo
fclean: clean
	$(MAKE) -C $(LIBFT_DIR) fclean
	rm -f $(SERVER) $(CLIENT)

# Reconstruir todo
re: fclean all

# Evitar que Make interprete los nombres de los archivos como comandos
.PHONY: all clean fclean re

