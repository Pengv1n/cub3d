/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:14 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:18 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include_bonus/cub3d_bonus.h"

void	draw_border(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	while (x < MINIMAP_W + (2 * BORDER))
	{
		y = 0;
		while (y < MINIMAP_H + (2 * BORDER))
		{
			if ((x <= BORDER || x > MINIMAP_W)
				|| (y <= BORDER || y > MINIMAP_H))
				modif_mlx_pixel_put(data->ptr_img,
					x + PADDING_X, y + PADDING_Y, BORDER_COLOR);
			y++;
		}
		x++;
	}
}

void	draw_elem(t_data *data, int px_x, int px_y)
{
	double	x;
	double	y;

	x = data->player_pos_x - (double)(DIST_PER_PIXEL * (CENTER_X - px_x));
	y = data->player_pos_y - (double)(DIST_PER_PIXEL * (CENTER_Y - px_y));
	if (x > 0.0 && y > 0.0 && y < data->y_max
		&& (int)x < ft_strlen(data->map[(int)y])
		&& data->map[(int)y][(int)x] == '1')
		modif_mlx_pixel_put(data->ptr_img, px_x + PADDING_X + BORDER,
			px_y + PADDING_Y + BORDER, WALL_COLOR);
}

void	draw_player(t_data *data)
{
	int		x;
	int		y;
	double	t;

	x = MINIMAP_W / 2 - 2;
	while (x < ((MINIMAP_W / 2) + 2))
	{
		y = MINIMAP_H / 2 - 2;
		while (y < ((MINIMAP_H / 2) + 2))
		{
			modif_mlx_pixel_put(data->ptr_img, x + PADDING_X + BORDER,
				y + PADDING_Y + BORDER, PLAYER_COLOR);
			y++;
		}
		x++;
	}
}

void	map2d(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	if (data->width_screen < 300 || data->height_screen < 300)
		return ;
	draw_border(data);
	while (x < MINIMAP_W)
	{
		y = 0;
		while (y < MINIMAP_H)
		{
			draw_elem(data, x, y);
			y++;
		}
		x++;
	}
	draw_player(data);
}
