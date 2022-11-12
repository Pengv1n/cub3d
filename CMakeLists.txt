cmake_minimum_required(VERSION 3.10)

# set the project name
#set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Imlx -lXext -lX11 -lm -lz -I minilibx/")
project(cub3d)

# add the executable
add_executable(cub3d src/main.c
        src/init_data.c
        src/init_mlx.c
        src/parser/open_file.c
        src/init_map.c
        src/clean_exit.c
        src/free_utils.c
        get_next_line/get_next_line.c

        src/parser/read_file.c
        src/parser/open_file.c
        src/parser/element_parsing.c
        src/parser/parse_utils.c
        src/parser/check_rgb.c
        src/parser/map_parsing.c
        src/parser/check_map.c
        src/parser/get_player_pos.c
        src/parser/check_map_utils.c
        src/parser/check_around_space.c

        src/game/game_utils.c
        src/game/textures.c
        src/game/init_raycast.c
        src/game/loop_mlx.c
        src/game/choice_textute.c
        src/game/player_move.c
        src/game/raycasting.c
        )

#add_compile_options(-Imlx -lXext -lX11 -lm -lz)
#add_link_options(-Imlx -lXext -lX11 -lm -lz)
#target_compile_options(cub3d PUBLIC -Imlx -lXext -lX11 -lm -lz)
target_link_libraries(cub3d LINK_PUBLIC /home/aregenia/school21/cub3d/libft/libft.a
        /home/aregenia/school21/cub3d/minilibx/libmlx.a
        -Imlx Xext X11 m z bsd)