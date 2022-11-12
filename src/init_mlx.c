#include "../cub3d.h"

void	init_mlx(t_data *data)
{
	data->mlx->mlx = mlx_init();
	if (!data->mlx->mlx)
		clean_exit(data, -1, 2, "Error: mlx_init failed\n");
	data->mlx->win = mlx_new_window(data->mlx->mlx, data->width_screen,
									data->height_screen, "Cub3D");
	if (!data->mlx->win)
		clean_exit(data, -1, 2, "ErrorL mlx_new_window failed\n");
}