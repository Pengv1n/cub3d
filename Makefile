CC := gcc

NAME := cub3d

MINILIBX_DIR := minilibx_linux
MINILIBX_LIB := $(MINILIBX_DIR)/libmlx_Linux.a

FLAGS := -Wall -Wextra -Werror
#MINILIBX_FLAGS := -L$(MINILIBX_DIR) -lmlx -lz -lm	\
#                      -framework OpenGL					\
#                      -framework AppKit
MINILIBX_FLAGS := -Imlx -lXext -lX11 -lm -lz

LIBFT_DIR := libft
LIBFT := $(LIBFT_DIR)/libft.a

HEADERS :=	Include/cub3d.h \
			Include/get_next_line.h

HEADERS_BONUS :=	Include_bonus/cub3d_bonus.h \
					Include_bonus/get_next_line_bonus.h

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

SRC_DIR_BONUS := src_bonus
SRC_BONUS_ :=	main_bonus.c							\
                init_data_bonus.c						\
                init_mlx_bonus.c						\
                init_map_bonus.c						\
                clean_exit_bonus.c						\
                free_utils_bonus.c						\
                parser_bonus/read_file_bonus.c			\
                parser_bonus/open_file_bonus.c			\
                parser_bonus/element_parsing_bonus.c	\
                parser_bonus/parse_utils_bonus.c		\
                parser_bonus/check_rgb_bonus.c			\
                parser_bonus/map_parsing_bonus.c		\
                parser_bonus/check_map_bonus.c			\
                parser_bonus/get_player_pos_bonus.c		\
                parser_bonus/check_map_utils_bonus.c	\
                parser_bonus/check_around_space_bonus.c	\
                game_bonus/game_utils_bonus.c			\
                game_bonus/textures_bonus.c				\
                game_bonus/init_raycast_bonus.c			\
                game_bonus/loop_mlx_bonus.c				\
                game_bonus/choice_textute_bonus.c		\
                game_bonus/player_move_bonus.c			\
                game_bonus/raycasting_bonus.c			\
                game_bonus/mouse_utils_bonus.c			\
                get_next_line_bonus/get_next_line_bonus.c

SRC := 	$(addprefix $(SRC_DIR)/,$(SRC_))

SRC_BONUS := $(addprefix $(SRC_DIR_BONUS)/,$(SRC_BONUS_))

OBJ_DIR := obj

INCLUDES 		:= -I$(LIBFT_DIR) -I Include -I$(MINILIBX_DIR)
INCLUDES_BONUS 	:= -I$(LIBFT_DIR) -I Include_bonus -I$(MINILIBX_DIR)

.o: .c
		$(CC) $(FLAGS) $(INCLUDES) -c $< -o $@

OBJ := $(SRC:.c=.o)
OBJ_BONUS := $(SRC_BONUS:.c=.o)

all:
	$(MAKE) -j $(NAME)

$(NAME): $(OBJ) $(SRC)
	make -C $(MINILIBX_DIR) all
	make -C $(LIBFT_DIR) all
	$(CC) $(OBJ) $(LIBFT) $(MINILIBX_LIB) $(FLAGS) $(INCLUDES) -o $(NAME) $(MINILIBX_FLAGS)

bonus: $(OBJ_BONUS) $(SRC_BONUS)
	make -C $(MINILIBX_DIR) all
	make -C $(LIBFT_DIR) all
	$(CC) $(OBJ_BONUS) $(LIBFT) $(MINILIBX_LIB) $(FLAGS) $(INCLUDES_BONUS) -o $(NAME) $(MINILIBX_FLAGS)

clean:
	make -C $(MINILIBX_DIR) clean
	make -C $(LIBFT_DIR) clean
	rm -rf $(OBJ)
	rm -rf $(OBJ_BONUS)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	rm -f $(NAME)

re:		fclean all

.PHONY:	all clean fclean re bonus
