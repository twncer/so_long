NAME = sl.a
CC = cc
CFLAGS = -Wall -Wextra -Werror

SOURCES = main.c \
			map_control.c \
			libsl/libslpg1.c \
			libsl/sl_split.c

OBJ = $(SOURCES:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	ar -rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ) 
a
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re