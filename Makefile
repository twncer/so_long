NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = vendor/minilibx-linux
MLX_FLAGS = -lXext -lX11
LIBMLX_DIR = vendor/minilibx-linux/libmlx_Linux.a
#-lmlx -lXext -lX11 -lm -lz -lpthread

SOURCES = \
		window.c \
		terminate.c \
		vendor/libsl/libsl_page_1.c \
		vendor/libsl/sl_split.c \
		movement/movement.c \
		movement/listen_keys.c \
		map/map_control.c \
		render/render.c \
		render/init_images.c \
		render/free_images.c \
		player/player.c \
		animate/animate_flowey.c \
		animate/animate_player.c \
		animate/animate_pellets.c \
		animate/animate_exit.c \
		collectibles/collect.c \
		enemy_shoot/shoot.c \
		sequences/sequences.c \

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIBMLX_DIR) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

clean:
	rm -f $(OBJ) 

fclean: clean
	rm -f $(NAME)

re: fclean all

run: re
	rm -f $(OBJ)
	./$(NAME) ./maps/flowerbed_short.ber

.PHONY: all clean fclean re