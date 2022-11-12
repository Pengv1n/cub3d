#include "../../cub3d.h"

void	fill_path(t_data *data)
{
	data->txts[NO_WALL].path = data->elem[0].path;
	data->txts[SO_WALL].path = data->elem[1].path;
	data->txts[WE_WALL].path = data->elem[2].path;
	data->txts[EA_WALL].path = data->elem[3].path;
}

int	modify_mlx_new_img(void *mlx_ptr, t_img *image_str, int res_x, int res_y)
{
	image_str->img = mlx_new_image(mlx_ptr, res_x, res_y);
	if (!image_str->img)
		return (0);
	image_str->addr = mlx_get_data_addr(image_str->img, &image_str->bpp,
		&image_str->size_line, &image_str->endian);
	return (1);
}

void	modif_mlx_pixel_put(t_img *image_str, int x, int y, int color)
{
	char	*dst;

	dst = image_str->addr + (y * image_str->size_line + x
			* (image_str->bpp / 8));
	*(unsigned int *)dst = color;
}

int	init_txts_struct(t_data *data)
{
	fill_path(data);
	if (!modify_mlx_new_img(data->mlx->mlx, data->ptr_img,
		data->width_screen, data->height_screen))
		return (0);
	if (!loading_txts(data, &data->txts[NO_WALL])
		|| !loading_txts(data, &data->txts[SO_WALL])
		|| !loading_txts(data, &data->txts[WE_WALL])
		|| !loading_txts(data, &data->txts[EA_WALL]))
		return (0);
	return (1);
}

int	game_launcher(t_data *data)
{
	if (!init_txts_struct(data))
		clean_exit(data, -1, 2, "Error: textures loading failed\n");
	init_plan(data);
	init_ray_dir(data);
}