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

#include "../../cub3d.h"

void	move_up_down(t_data *data, t_raycast *rc)
{
	if (data->key_w == 1)
	{
		if (data->map[(int)data->player_pos_y]
			[(int)(data->player_pos_x + rc->dir_x * SPEED)] != '1')
			data->player_pos_x +=rc->dir_x * SPEED;
		if (data->map[(int)(data->player_pos_y + rc->dir_y * SPEED)]
			[(int)data->player_pos_x] != '1')
			data->player_pos_y += rc->dir_y * SPEED;
	}
	if (data->key_s == 1)
	{
		if (data->map[(int)data->player_pos_y]
			[(int)(data->player_pos_x - rc->dir_x * SPEED)] != '1')
			data->player_pos_x -= rc->dir_x * SPEED;
		if (data->map[(int)(data->player_pos_y - rc->dir_y * SPEED)]
			[(int)data->player_pos_x] != '1')
			data->player_pos_y -= rc->dir_y * SPEED;
	}
}

void	move_left_right(t_data *data, t_raycast *rc)
{
	if (data->key_a == 1)
	{
		if (data->map[(int)(data->player_pos_y - rc->dir_x * SPEED)]
			[(int)(data->player_pos_x + rc->dir_y * SPEED)] != '1')
		{
			data->player_pos_x += rc->dir_y * SPEED;
			data->player_pos_y -= rc->dir_x * SPEED;
		}
	}
	else if (data->key_d == 1)
	{
		if (data->map[(int)(data->player_pos_y - rc->dir_x * SPEED)]
			[(int)(data->player_pos_x - rc->dir_y * SPEED)] != '1')
		{
			data->player_pos_x -= rc->dir_y * SPEED;
			data->player_pos_y += rc->dir_x * SPEED;
		}
	}
}

void	rotate_left_or_right(t_data *data, t_raycast *rc)
{
	double	dir_x_old;
	double	plane_x_old;
	int		rotate;

	if (data->key_rotate_left == 1)
		rotate = -1;
	else
		rotate = 1;
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

void	player_move(t_data *data, t_raycast *rc)
{
	if (data->key_w == 1 || data->key_s == 1)
		move_up_down(data, rc);
	if (data->key_a == 1 || data->key_d == 1)
		move_left_right(data, rc);
	if (data->key_rotate_left == 1 || data->key_rotate_right == 1)
		rotate_left_or_right(data, rc);
}
