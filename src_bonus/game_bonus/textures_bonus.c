/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:39 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:40 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include_bonus/cub3d_bonus.h"

int	loading_txts(t_data *data, t_txt *texture)
{
	int	i;
	int	stop_load;

	if (!texture->path)
		return (0);
	texture->img = mlx_xpm_file_to_image(data->mlx->mlx, texture->path,
			&texture->width, &texture->height);
	if (!texture->img)
		return (0);
	texture ->addr = (unsigned int *) mlx_get_data_addr(texture->img,
			&texture->bpp, &texture->size_line, &texture->endian);
	texture->txt = ft_calloc(texture->width * texture->height,
			sizeof(unsigned int));
	if (!texture->txt)
		return (0);
	i = -1;
	stop_load = texture->width * texture->height;
	while (++i < stop_load)
		texture->txt[i] = texture->addr[i];
	return (1);
}

int	ft_plan(t_raycast *rc)
{
	int	side;

	side = 0;
	if (rc->side == 0)
	{
		if (rc->step_x < 0)
			side = 3;
		else
			side = 1;
	}
	else
	{
		if (rc->step_y < 0)
			side = 0;
		else
			side = 2;
	}
	return (side);
}

int	algo_txts_x(t_raycast *rc, t_txt *txt, int side)
{
	int		txt_x;
	double	wall_x;

	txt_x = 0;
	wall_x = 0;
	if (rc->side == 0)
		wall_x = rc->pos_y + rc->perp_wall_dist * rc->ray_dir_y;
	else
		wall_x = rc->pos_x + rc->perp_wall_dist * rc->ray_dir_x;
	wall_x = wall_x - floor(wall_x);
	txt_x = (int)(wall_x * (double)txt->width);
	if (side == 0)
		txt_x = txt->width - txt_x - 1;
	if (side == 3)
		txt_x = txt->width - txt_x - 1;
	return (txt_x);
}

int	print_txts_helper(t_data *data, t_txt *txt, int y, int x)
{
	double	txt_y;
	int		color;

	txt_y = 0.0;
	color = 0;
	while (y >= data->raycast->draw_start && y < data->raycast->draw_end)
	{
		txt_y = (int)(((y - data->height_screen
						/ 2 + data->raycast->line_height / 2)
					* txt->height) / data->raycast->line_height);
		color = txt->txt[txt->width * (int)floor(txt_y) + txt->txts_x];
		modif_mlx_pixel_put(data->ptr_img, x, y, color);
		++y;
	}
	return (y);
}

void	print_txts(int x, t_data *data, t_raycast *rc)
{
	int	y;
	int	side;
	int	rgb[2];
	int	txt_wall;

	y = 0;
	side = ft_plan(rc);
	txt_wall = choice_texture(side);
	data->txts[txt_wall].txts_x = algo_txts_x(rc,
			&data->txts[txt_wall], side);
	rgb[0] = trgb_convert(0, data->elem[5].rgb[0],
			data->elem[5].rgb[1], data->elem[5].rgb[2]);
	rgb[1] = trgb_convert(0, data->elem[4].rgb[0],
			data->elem[4].rgb[1], data->elem[4].rgb[2]);
	while (y < rc->draw_start)
		modif_mlx_pixel_put(data->ptr_img, x, y++, rgb[0]);
	y = print_txts_helper(data, &data->txts[txt_wall], y, x);
	while (rc->draw_end <= y && y < data->height_screen)
		modif_mlx_pixel_put(data->ptr_img, x, y++, rgb[1]);
}
