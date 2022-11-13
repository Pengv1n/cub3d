/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_raycast.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:09 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:10 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

void	init_plan(t_data *data)
{
	double	dir;

	dir = data->player_dir;
	if (dir > (5 * M_PI) / 4 && dir <= (7 * M_PI) / 4)
	{
		data->raycast->plane_x = 0.0;
		data->raycast->plane_y = 0.66;
	}
	else if (dir > (7 * M_PI) / 4 || dir <= M_PI / 4)
	{
		data->raycast->plane_x = 0.66;
		data->raycast->plane_y = 0.0;
	}
	else if (dir > M_PI / 4 && dir <= (3 * M_PI) / 4)
	{
		data->raycast->plane_x = 0.0;
		data->raycast->plane_y = -0.66;
	}
	else if (dir > (3 * M_PI) / 4 && dir <= (5 * M_PI) / 4)
	{
		data->raycast->plane_x = -0.66;
		data->raycast->plane_y = 0.0;
	}
}

void	init_ray_dir(t_data *data)
{
	double	dir;

	dir = data->player_dir;
	if (dir > (5 * M_PI) / 4 && dir <= (7 * M_PI) / 4)
	{
		data->raycast->dir_x = -1.0;
		data->raycast->dir_y = 0.0;
	}
	else if (dir > (7 * M_PI) / 4 || dir <= M_PI / 4)
	{
		data->raycast->dir_x = 0.0;
		data->raycast->dir_y = 1.0;
	}
	else if (dir > M_PI / 4 && dir <= (3 * M_PI) / 4)
	{
		data->raycast->dir_x = 1.0;
		data->raycast->dir_y = 0.0;
	}
	else if (dir > (3 * M_PI) / 4 && dir <= (5 * M_PI) / 4)
	{
		data->raycast->dir_x = 0.0;
		data->raycast->dir_y = -1.0;
	}
}
