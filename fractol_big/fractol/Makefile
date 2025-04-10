NAME		= fractol

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -O3

MLX_DIR		= ./minilibx-linux/
MLX_FLAGS	= -L$(MLX_DIR) -lmlx -lXext -lX11 -lm
INCLUDE		= -I$(MLX_DIR)

SRC_DIR		= src/
OBJ_DIR		= obj/

SRC_FILES	= main.c fractol.c events.c zoom.c move.c color.c utils.c fractals.c
SRC			= $(addprefix $(SRC_DIR), $(SRC_FILES))
OBJ			= $(addprefix $(OBJ_DIR), $(SRC_FILES:.c=.o))

all: $(NAME)

$(NAME): $(OBJ)
	@$(CC) $(OBJ) $(MLX_FLAGS) -o $(NAME)

$(OBJ_DIR)%.o: $(SRC_DIR)%.c
	@mkdir -p $(OBJ_DIR)
	@$(CC) $(CFLAGS) $(INCLUDE) -c $< -o $@

clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
