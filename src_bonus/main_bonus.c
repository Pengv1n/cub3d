/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:40 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:41 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include_bonus/cub3d_bonus.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	if (argc != 2)
		clean_exit(&data, -1, 2, "Usage: \"./cub3D map_file.cub\"\n");
	init_data(&data);
	init_mlx(&data);
	init_map(&data, argv[1]);
	read_file(&data, argv[1]);
	game_launcher(&data);
	mlx_mouse_hide(data.mlx->mlx, data.mlx->win);
	game_loop(&data);
	return (0);
}
