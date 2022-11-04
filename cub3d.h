#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

#include "stdio.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
#include <fcntl.h>
#include "get_next_line/get_next_line.h"

typedef struct s_txt
{

}	t_txt;

typedef struct s_raycast
{

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
	int		*id;
	char	*path;
	int		rgb[3];
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
} t_data;

void	init_data(t_data *data);
void	init_mlx(t_data *data);
int		open_file(char *path);
void	init_map(t_data *data, char *path);
void	skip_spaces(char **line);

#endif //CUB3D_CUB3D_H