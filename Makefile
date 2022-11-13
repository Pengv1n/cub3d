CC := gcc

NAME := cub3d

MINILIBX_DIR := minilibx_opengl_20191021
MINILIBX_LIB := $(MINILIBX_DIR)/libmlx.a

FLAGS := -Wall -Wextra -Werror
MINILIBX_FLAGS_MAC := -L$(MINILIBX_DIR) -lmlx -lz -lm	\
                      -framework OpenGL					\
                      -framework AppKit

#MINILIBX_FLAGS_LINUX := -Imlx -lXext -lX11 -lm -lz

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

HEADERS :=	Include/cub3d.h \
			Include/get_next_line.h

SRC_DIR := src
SRC_ :=			main.c						\
                init_data.c					\
                init_mlx.c					\
                init_map.c					\
                clean_exit.c				\
                free_utils.c				\
                parser/read_file.c			\
                parser/open_file.c			\
                parser/element_parsing.c	\
                parser/parse_utils.c		\
                parser/check_rgb.c			\
                parser/map_parsing.c		\
                parser/check_map.c			\
                parser/get_player_pos.c		\
                parser/check_map_utils.c	\
                parser/check_around_space.c	\
                game/game_utils.c			\
                game/textures.c				\
                game/init_raycast.c			\
                game/loop_mlx.c				\
                game/choice_textute.c		\
                game/player_move.c			\
                game/raycasting.c			\
                get_next_line/get_next_line.c

SRC := 	$(addprefix $(SRC_DIR)/,$(SRC_))

OBJ_DIR := obj

INCLUDES := -I$(LIBFT_DIR) -I Include -I$(MINILIBX_DIR)

OBJ :=	$(addprefix $(OBJ_DIR)/,$(SRC_:.c=.o))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(HEADERS)
	$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

all: $(OBJ_DIR)
	$(MAKE) -j $(NAME)
$(OBJ_DIR):
	mkdir -p $@
	mkdir -p $@/parser
	mkdir -p $@/game
	mkdir -p $@/get_next_line

$(NAME): $(OBJ) $(SRC)
	make -C $(MINILIBX_DIR) all
	make -C $(LIBFT_DIR) all
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX_LIB) $(FLAGS) -o $(NAME) $(MINILIBX_FLAGS_MAC)

clean:
	make -C $(MINILIBX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ_DIR)
fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re