/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:55:06 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:55:12 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

#include <stdio.h>
#include "libft/libft.h"
#include "minilibx_opengl_20191021/mlx.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"
#include <math.h>

#define NO_WALL			0
#define SO_WALL			1
#define EA_WALL			2
#define WE_WALL			3

# define SPEED			0.15
# define ROTATE			0.10

#define XPM 1
#define PNG 2

#ifdef __APPLE__
# define A_KEY 			0
# define S_KEY			1
# define D_KEY			2
# define W_KEY			13
# define LEFT_ARROW		123
# define RIGHT_ARROW	124
# define ESCAPE			53
#else
# define A_KEY 			97
# define S_KEY			115
# define D_KEY			100
# define W_KEY			119
# define LEFT_ARROW		65361
# define RIGHT_ARROW	65363
# define ESCAPE			65307
#endif

typedef struct s_txt
{
	void			*img;
	unsigned int	*addr;
	unsigned int	*txt;
	int				bpp;
	int				endian;
	int				size_line;
	int				width;
	int				height;
	int				txts_x;
	char			*path;
    int             type;
}	t_txt;

typedef struct s_raycast
{
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	int		map_x;
	int		map_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	int		step_x;
	int		step_y;
	int		side;
	int		line_height;
	int		draw_start;
	int		draw_end;
}	t_raycast;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
} t_mlx;

typedef struct s_elem
{
	char	*id;
	char	*path;
	int		rgb[3];
	int     type;
} t_elem;

typedef struct s_data
{
	t_elem	elem[6];
	t_mlx	*mlx;
	t_img 	*ptr_img;
	t_raycast	*raycast;
	int	height_screen;
	int	width_screen;
	t_txt	txts[4];
	int		y_max;
	char	**map;
	double	player_dir;
	double	player_pos_x;
	double	player_pos_y;
	int				key_w;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_rotate_left;
	int				key_rotate_right;
} t_data;

void	init_data(t_data *data);
void	init_mlx(t_data *data);
int		open_file(char *path);
void	init_map(t_data *data, char *path);
int		skip_spaces(char **line);
void	free_split(char **split);
void	clean_free_tmp_split(char *tmp, char **split);
int		substitute_coma(char *line);
int		ft_strcmp(char *s1, char *s2);
int		get_int_value(t_elem *elem, char **split);
int		element_parsing(t_data *data, int fd);
void	free_all(t_data *data);
void	clean_exit(t_data *data, int fd_gnl, int fd, char *msg);
int		get_player_pos(t_data *data);
int		check_empty_spaces(t_data *data, int i, int j);
int		check_around_space(t_data *data, int pos_i, int pos_j);
int		check_map(t_data *data);
int		map_parsing(t_data *data, int fd);
int		read_file(t_data *data, char *path);
int		check_extension(char *path, const char *type);
int		check_nb_element_rgb(char **info);
int		loading_txts(t_data *data, t_txt *texture);
void	init_plan(t_data *data);
void	init_ray_dir(t_data *data);
int		game_launcher(t_data *data);
void	player_move(t_data *data, t_raycast *rc);
int		choice_texture(int side);
int		trgb_convert(int i, int r, int g, int b);
void	modif_mlx_pixel_put(t_img *image_str, int x, int y, int color);
void	print_txts(int x, t_data *data, t_raycast *rc);
int		raycasting(t_data *data, t_raycast *rc);
void	game_loop(t_data *data);
int		check_texture_path(t_elem *txt, char *path);

#endif //CUB3D_CUB3D_H
