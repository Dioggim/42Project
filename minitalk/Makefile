NAME = server
CLIENT = client

CC = cc
CFLAGS = -Wall -Wextra -Werror

LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

SRC_SERVER = server.c
SRC_CLIENT = client.c

OBJ_SERVER = $(SRC_SERVER:.c=.o)
OBJ_CLIENT = $(SRC_CLIENT:.c=.o)

all: $(LIBFT) $(NAME) $(CLIENT)

$(LIBFT):
	@make -C $(LIBFT_PATH)

$(NAME): $(OBJ_SERVER)
	$(CC) $(CFLAGS) $(OBJ_SERVER) $(LIBFT) -o $(NAME)

$(CLIENT): $(OBJ_CLIENT)
	$(CC) $(CFLAGS) $(OBJ_CLIENT) $(LIBFT) -o $(CLIENT)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	@make clean -C $(LIBFT_PATH)
	rm -f $(OBJ_SERVER) $(OBJ_CLIENT)

fclean: clean
	@make fclean -C $(LIBFT_PATH)
	rm -f $(NAME) $(CLIENT)

re: fclean all

.PHONY: all clean fclean re
