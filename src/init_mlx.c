#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		;
	data->mlx->win = mlx_new_window(data->mlx->mlx, data->width_screen,
									data->height_screen, "Cub3D");
	if (!data->mlx->win)
		;
}