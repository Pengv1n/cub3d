CC := gcc

NAME := cub3d

FLAGS := #-Wall -Wextra -Werror
MINILIBX_FLAGS := -Imlx -lXext -lX11 -lm -lz

MINILIBX_DIR := minilibx
MINILIBX_LIB := $(MINILIBX_DIR)/libmlx.a

LIBFT_DIR := libft
LIBFT := libft.a

HEADERS :=	cub3d.h

SRC_DIR := src
SRC_ :=	main.c	\
		check.c
SRC := $(addprefix $(SRC_DIR)/,$(SRC_))

OBJ_DIR := obj

INCLUDES := -I $(LIBFT_DIR) $(SRC_DIR)

OBJ := $(addprefix $(OBJ_DIR)/,$(SRC_:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(FLAGS) $(MINILIBX_FLAGS) $(INCLUDES) -c $< -o $@

all: $(OBJ_DIR)
	$(MAKE) -j $(NAME)
$(OBJ_DIR):
	mkdir -p $@

$(NAME): $(OBJ) $(SRC)
	make -C $(LIBFT_DIR)/ all
	$(CC) $(OBJ) $(LIBFT_DIR)/$(LIBFT) $(MINILIBX_LIB) $(FLAGS) -o $(NAME) $(MINILIBX_FLAGS)

clean:
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re