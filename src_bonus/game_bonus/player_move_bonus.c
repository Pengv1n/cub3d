/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:23 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:25 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include_bonus/cub3d_bonus.h"

void	move_up_down(t_data *data, t_raycast *rc)
{
	if (data->key_w == 1)
	{
		if (data->map[(int)data->player_pos_y]
			[(int)(data->player_pos_x + rc->dir_x * CHECK_SPEED)] != '1')
			data->player_pos_x += rc->dir_x * SPEED;
		if (data->map[(int)(data->player_pos_y + rc->dir_y * CHECK_SPEED)]
			[(int)data->player_pos_x] != '1')
			data->player_pos_y += rc->dir_y * SPEED;
	}
	if (data->key_s == 1)
	{
		if (data->map[(int)data->player_pos_y]
			[(int)(data->player_pos_x - rc->dir_x * CHECK_SPEED)] != '1')
			data->player_pos_x -= rc->dir_x * SPEED;
		if (data->map[(int)(data->player_pos_y - rc->dir_y * CHECK_SPEED)]
			[(int)data->player_pos_x] != '1')
			data->player_pos_y -= rc->dir_y * SPEED;
	}
}

void	move_left_right(t_data *data, t_raycast *rc)
{
	if (data->key_a == 1)
	{
		if (data->map[(int)(data->player_pos_y - rc->dir_x * CHECK_SPEED / 2)]
			[(int)(data->player_pos_x + rc->dir_y * CHECK_SPEED / 2)] != '1')
		{
			data->player_pos_x += rc->dir_y * SPEED / 2;
			data->player_pos_y -= rc->dir_x * SPEED / 2;
		}
	}
	else if (data->key_d == 1)
	{
		if (data->map[(int)(data->player_pos_y + rc->dir_x * CHECK_SPEED / 2)]
			[(int)(data->player_pos_x - rc->dir_y * CHECK_SPEED / 2)] != '1')
		{
			data->player_pos_x -= rc->dir_y * SPEED / 2;
			data->player_pos_y += rc->dir_x * SPEED / 2;
		}
	}
}

void	rotate_left_or_right(t_raycast *rc, double rotate)
{
	double	dir_x_old;
	double	plane_x_old;

	dir_x_old = rc->dir_x;
	rc->dir_x = rc->dir_x * cos(rotate * ROTATE)
		- rc->dir_y * sin(rotate * ROTATE);
	rc->dir_y = dir_x_old * sin(rotate * ROTATE)
		+ rc->dir_y * cos(rotate * ROTATE);
	plane_x_old = rc->plane_x;
	rc->plane_x = rc->plane_x * cos(rotate * ROTATE)
		- rc->plane_y * sin(rotate * ROTATE);
	rc->plane_y = plane_x_old * sin(rotate * ROTATE)
		+ rc->plane_y * cos(rotate * ROTATE);
}

void	ft_mouse(t_data *data, t_raycast *rc)
{
	int	x;
	int	y;

	if (data->pred_x != 10000)
	{
		mlx_mouse_get_pos(data->mlx->mlx, data->mlx->win, &x, &y);
		if (data->pred_x == x)
			return ;
		if (x == data->width_screen - 1 || x == 0)
			return (edge_screen(data, x, y));
		rotate_left_or_right(rc, (x - data->pred_x) / 5.0);
	}
	else
	{
		mlx_mouse_move(data->mlx->mlx, data->mlx->win,
			data->width_screen / 2, data->height_screen / 2);
		x = data->width_screen / 2;
	}
	data->pred_x = x;
}

void	player_move(t_data *data, t_raycast *rc)
{
	if (data->key_w == 1 || data->key_s == 1)
		move_up_down(data, rc);
	if (data->key_a == 1 || data->key_d == 1)
		move_left_right(data, rc);
	if (data->key_rotate_left == 1)
		rotate_left_or_right(rc, -1);
	if (data->key_rotate_right == 1)
		rotate_left_or_right(rc, 1);
	ft_mouse(data, data->raycast);
}
