
cmake_minimum_required(VERSION 3.10)

project(cub3d)

project(cub3d_bonus)

add_executable(cub3d_bonus src_bonus/main_bonus.c
        src_bonus/init_data_bonus.c
        src_bonus/init_mlx_bonus.c
        src_bonus/parser_bonus/open_file_bonus.c
        src_bonus/init_map_bonus.c
        src_bonus/clean_exit_bonus.c
        src_bonus/free_utils_bonus.c

        src_bonus/get_next_line_bonus/get_next_line_bonus.c

        src_bonus/parser_bonus/read_file_bonus.c
        src_bonus/parser_bonus/open_file_bonus.c
        src_bonus/parser_bonus/element_parsing_bonus.c
        src_bonus/parser_bonus/parse_utils_bonus.c
        src_bonus/parser_bonus/check_rgb_bonus.c
        src_bonus/parser_bonus/map_parsing_bonus.c
        src_bonus/parser_bonus/check_map_bonus.c
        src_bonus/parser_bonus/get_player_pos_bonus.c
        src_bonus/parser_bonus/check_map_utils_bonus.c
        src_bonus/parser_bonus/check_around_space_bonus.c

        src_bonus/game_bonus/game_utils_bonus.c
        src_bonus/game_bonus/textures_bonus.c
        src_bonus/game_bonus/init_raycast_bonus.c
        src_bonus/game_bonus/loop_mlx_bonus.c
        src_bonus/game_bonus/choice_textute_bonus.c
        src_bonus/game_bonus/player_move_bonus.c
        src_bonus/game_bonus/raycasting_bonus.c
        src_bonus/game_bonus/mouse_utils_bonus.c
)

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

add_custom_target(mlx ALL COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/minilibx_linux)
add_custom_target(libft ALL COMMAND make -C ${CMAKE_CURRENT_SOURCE_DIR}/libft)

find_library(LIBFT ft libft)
include_directories(minilibx_linux)
include_directories(minilibx)

find_library(MINILIBX_LINUX NAMES mlx_Linux PATHS minilibx_linux NO_DEFAULT_PATH)
find_library(MINILIBX NAMES mlx PATHS minilibx NO_DEFAULT_PATH)

target_include_directories(cub3d PUBLIC Include)
target_include_directories(cub3d_bonus PUBLIC Include_bonus)

if (APPLE)
    find_library(OPENGL_LIB OpenGL)
    find_library(APPKIT_LIB AppKit)
    set(MLX_LIB z m ${OPENGL_LIB} ${APPKIT_LIB})

    target_link_libraries(cub3d LINK_PUBLIC ${LIBFT}
            ${MINILIBX}
            ${MLX_LIB})
else ()
    target_link_libraries(cub3d LINK_PUBLIC ${LIBFT}
            ${MINILIBX_LINUX}
            -Imlx Xext X11 m z bsd)

    target_link_libraries(cub3d_bonus LINK_PUBLIC ${LIBFT}
            ${MINILIBX_LINUX}
            -Imlx Xext X11 m z bsd)
endif()