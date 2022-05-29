cmake_minimum_required(VERSION 3.22)
project(cub3d C)

set(CMAKE_C_STANDARD 99)

#file(GLOB SOURCES
#        libft/*.h
#        libft/*.c
#        )

add_executable(cub3d ${SOURCES}
                main.c
                check.c
        )

#find_library(LIB lib minilibx)
target_link_libraries(cub3d /home/aregenia/school21/cub3d/libft/libft.a
        )
target_link_libraries(cub3d /home/aregenia/school21/cub3d/minilibx/libmlx.a
        )