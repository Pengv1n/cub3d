/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:31 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:33 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include_bonus/cub3d_bonus.h"

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
