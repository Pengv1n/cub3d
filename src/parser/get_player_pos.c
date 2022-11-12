/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player_pos.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:58:51 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:58:52 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

void	save_player_dir(t_data *data, char dir, int i, int j)
{
	if (dir == 'S')
		data->player_dir = 0;
	else if (dir == 'N')
		data->player_dir = M_PI;
	else if (dir == 'W')
		data->player_dir = (3 * M_PI) / 2;
	else if (dir == 'E')
		data->player_dir = M_PI / 2;
	data->player_pos_x = (double)j + 0.5;
	data->player_pos_y = (double)i + 0.5;
}

void	return_error(t_data *data, int player)
{
	if (player == 0)
		clean_exit(data, -1, 2, "Error: no players in map\n");
	if (player > 1)
		clean_exit(data, -1, 2, "Error: severals players in map\n");
}

int	get_player_pos(t_data *data)
{
	int	i;
	int	j;
	int	player;

	player = 0;
	i = 0;
	j = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j]) {
			if (data->map[i][j] == 'N' || data->map[i][j] == 'S'
				|| data->map[i][j] == 'E' || data->map[i][j] == 'W') {
				save_player_dir(data, data->map[i][j], i, j);
				player++;
			}
			j++;
		}
		i++;
	}
	if (player != 1)
		return_error(data, player);
	return (0);
}
