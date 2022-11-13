
cmake_minimum_required(VERSION 3.10)

project(cub3d)

add_executable(cub3d src/main.c
        src/init_data.c
        src/init_mlx.c
        src/parser/open_file.c
        src/init_map.c
        src/clean_exit.c
        src/free_utils.c
        src/get_next_line/get_next_line.c

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

add_custom_target(mlx ALL COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_opengl_20191021)
add_custom_target(libft ALL COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/libft)

find_library(LIBFT ft libft)

if (APPLE)
    include_directories(minilibx_opengl_20191021)
    find_library(MINILIBX mlx minilibx_opengl_20191021)
    find_library(OPENGL_LIB OpenGL)
    find_library(APPKIT_LIB AppKit)
    set(MLX_LIB z m ${OPENGL_LIB} ${APPKIT_LIB})

    target_link_libraries(cub3d LINK_PUBLIC ${LIBFT}
            ${MINILIBX}
            ${MLX_LIB})
else ()
    include_directories(minilibx)
    find_library(MINILIBX mlx minilibx)
    target_link_libraries(cub3d LINK_PUBLIC ${LIBFT}
            ${MINILIBX}
            -Imlx Xext X11 m z bsd)
endif()