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

void	drawLine(t_data *data, t_point *p1, t_point *p2)
{
	double	dx = p1->x - p2->x;
	double	dy = p1->y - p2->y;

	if (fabs(dx) > fabs(dy))
	{
		if (p1->x > p2->x)
		{
			double	tmp_x;
			double	tmp_y;

			tmp_x = p1->x;
			p1->x = p2->x;
			p2->x = tmp_x;
			tmp_y = p1->y;
			p1->y = p2->y;
			p2->y = tmp_y;
		}
		double	a = dy / dx;
		double y = p1->y;
		double	x = p2->x;
		while (p1->x < p2->x)
		{
			modif_mlx_pixel_put(data->ptr_img,
			(int)p1->x + MINIMAP_W / 2 - (int)x + PADDING_X + BORDER,
			(int)y + MINIMAP_H / 2 - (int)p2->y + PADDING_X + BORDER, PLAYER_COLOR);
			y = y + a;
			p1->x++;
		}
	}
	else
	{
		if (p1->y > p2->y)
		{
			double	tmp_x;
			double	tmp_y;

			tmp_x = p1->x;
			p1->x = p2->x;
			p2->x = tmp_x;
			tmp_y = p1->y;
			p1->y = p2->y;
			p2->y = tmp_y;
		}
		double  a = dx / dy;
		double	x = p1->x;
		double	y = p2->y;
		while (p1->y < p2->y)
		{
			modif_mlx_pixel_put(data->ptr_img,
			(int)x + MINIMAP_W / 2 - (int)p2->x + PADDING_X + BORDER,
			(int)p1->y + MINIMAP_H / 2 - (int)y + PADDING_X + BORDER, PLAYER_COLOR);
			x = x + a;
			p1->y++;
		}
	}
}

void	draw_player(t_data *data)
{
	int	x;
	int	y;
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
		return;
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
	double p_x = 5;
	double p_y = 5;
	if (data->raycast->dir_x < 0 && data->raycast->dir_y < 0)
	{

	}
	else if (data->raycast->dir_x < 0)
		p_x = -p_x;
	else if (data->raycast->dir_y < 0)
		p_y = -p_y;

//	drawLine(data, data->raycast->dir_x * 10,
//			 data->raycast->dir_y * 10);
//	drawLine(data, data->raycast->dir_x * 10 + p_x,
//			 data->raycast->dir_y * 10 + p_y);
//	drawLine(data, data->raycast->dir_x * 10 - p_x,
//			 data->raycast->dir_y * 10 - p_y) ;

//	draw_player(data);
}