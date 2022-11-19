/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:14 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:18 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include_bonus/cub3d_bonus.h"

void	edge_screen(t_data *data, int x, int y)
{
	if (x == data->width_screen - 1)
	{
		x = 0;
	}
	else if (x == 0)
	{
		x = data->width_screen - 1;
	}
	mlx_mouse_move(data->mlx->win, x, y);
	data->pred_x = x;
}
