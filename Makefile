NAME = so_long
CC = cc
CFLAGS = -Wall -Wextra -Werror
MLX_DIR = vendor/minilibx-linux
MLX_FLAGS = -lXext -lX11
LIBMLX_DIR = vendor/minilibx-linux/libmlx_Linux.a
#-lmlx -lXext -lX11 -lm -lz -lpthread

SOURCES = \
		mand.c \
		terminate.c \
		vendor/libsl/libsl_page_1.c \
		vendor/libsl/sl_split.c \
		map/map_control_utils.c \
		map/map_control.c \
		render/camera.c \
		render/put_image.c \
		render/render.c \
		render/init_images.c \
		render/free_images.c \
		player/player.c \
		collectibles/collect.c \

SOURCES_BONUS = \
		window.c \
		player/player.c \
		events.c \
		terminate.c \
		vendor/libsl/libsl_page_1.c \
		vendor/libsl/sl_split.c \
		movement/movement.c \
		movement/listen_keys.c \
		movement/display_moves.c \
		map/map_control_utils.c \
		map/map_control.c \
		render/put_image.c \
		render/render.c \
		render/camera.c \
		render/init_images.c \
		render/free_images.c \
		animate/animate_flowey.c \
		animate/animate_player.c \
		animate/animate_pellets.c \
		animate/animate_exit.c \
		collectibles/collect.c \
		enemy_shoot/shoot.c \
		sequences/sequences.c \

PRINTF_SOURCES = \
		vendor/ft_printf/ft_printf_utils.c \
		vendor/ft_printf/ft_utils.c \
		vendor/ft_printf/ft_printf.c \

OBJ = $(SOURCES:.c=.o)
OBJ_BONUS = $(SOURCES_BONUS:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(PRINTF_SOURCES) $(LIBMLX_DIR) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)

bonus: $(OBJ_BONUS)
	$(CC) $(CFLAGS) $(OBJ_BONUS) $(PRINTF_SOURCES) $(LIBMLX_DIR) -L$(MLX_DIR) $(MLX_FLAGS) -o $(NAME)_bonus

clean:
	rm -f $(OBJ) $(OBJ_BONUS)

fclean: clean
	rm -f $(NAME) $(NAME)_bonus

re: fclean all

re_bonus: fclean bonus

run_mand: re
	rm -f $(OBJ) $(OBJ_BONUS)
	./$(NAME) ./maps/flowerbed_short_mand.ber

run_bonus: re_bonus
	rm -f $(OBJ) $(OBJ_BONUS)
	./$(NAME)_bonus ./maps/flowerbed_short.ber

.PHONY: all clean fclean re