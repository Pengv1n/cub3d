/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:30 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:32 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	init_raycastring(t_data *data, int x)
{
	data->raycast->camera_x = 2.0
		* (double)(data->width_screen - 1 - x)
		/ (double)data->width_screen - 1;
	data->raycast->ray_dir_x = data->raycast->dir_x
		+ data->raycast->plane_x * data->raycast->camera_x;
	data->raycast->ray_dir_y = data->raycast->dir_y
		+ data->raycast->plane_y * data->raycast->camera_x;
	data->raycast->map_x = (int)data->raycast->pos_x;
	data->raycast->map_y = (int)data->raycast->pos_y;
	data->raycast->delta_dist_x = fabs(1 / data->raycast->ray_dir_x);
	data->raycast->delta_dist_y = fabs(1 / data->raycast->ray_dir_y);
}

void	side_dist(t_data *data, t_raycast *rc)
{
	if (rc->ray_dir_x < 0)
	{
		rc->step_x = -1;
		rc->side_dist_x = (data->player_pos_x - rc->map_x) * rc->delta_dist_x;
	}
	else
	{
		rc->step_x = 1;
		rc->side_dist_x = (rc->map_x + 1.0 - data->player_pos_x)
			* rc->delta_dist_x;
	}
	if (rc->ray_dir_y < 0)
	{
		rc->step_y = -1;
		rc->side_dist_y = (data->player_pos_y - rc->map_y) * rc->delta_dist_y;
	}
	else
	{
		rc->step_y = 1;
		rc->side_dist_y = (rc->map_y + 1.0 - data->player_pos_y)
			* rc->delta_dist_y;
	}
}

void	algo_dda(t_data *data, t_raycast *rc)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (rc->side_dist_x < rc->side_dist_y)
		{
			rc->side_dist_x += rc->delta_dist_x;
			rc->map_x += rc->step_x;
			rc->side = 0;
		}
		else
		{
			rc->side_dist_y += rc->delta_dist_y;
			rc->map_y += rc->step_y;
			rc->side = 1;
		}
		if (data->map[(int)rc->map_y][(int)rc->map_x] == '1')
			hit = 1;
	}
}

void	wall_dist(t_data *data)
{
	if (data->raycast->side == 0)
		data->raycast->perp_wall_dist = (data->raycast->map_x
				- data->player_pos_x + (1 - data->raycast->step_x) / 2)
			/ data->raycast->ray_dir_x;
	else
		data->raycast->perp_wall_dist = (data->raycast->map_y
				- data->player_pos_y + (1 - data->raycast->step_y) / 2)
			/ data->raycast->ray_dir_y;
	data->raycast->line_height = (int)data->height_screen
		/ data->raycast->perp_wall_dist;
	data->raycast->draw_start = (int)(-data->raycast->line_height) / 2
		+ data->height_screen / 2;
	if (data->raycast->draw_start < 0)
		data->raycast->draw_start = 0;
	data->raycast->draw_end = data->raycast->line_height / 2
		+ data->height_screen / 2;
	if (data->raycast->draw_end > data->height_screen)
		data->raycast->draw_end = data->height_screen;
}

int	raycasting(t_data *data, t_raycast *rc)
{
	int	x;

	x = -1;
	rc->pos_x = data->player_pos_x;
	rc->pos_y = data->player_pos_y;
	while (++x < data->width_screen)
	{
		init_raycastring(data, x);
		side_dist(data, rc);
		algo_dda(data, rc);
		wall_dist(data);
		print_txts(x, data, rc);
	}
	return (1);
}
