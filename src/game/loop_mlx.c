/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:57:14 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:57:18 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	exit_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->mlx->mlx, data->txts[i].img);
	mlx_destroy_image(data->mlx->mlx, data->ptr_img->img);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
	mlx_destroy_image(data->mlx->mlx, data->mlx->win);
	free_all(data);
	exit(1);
	return (1);
}

int	key_press(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_game(data);
	if (key == W_KEY)
		data->key_w = 1;
	if (key == A_KEY)
		data->key_a = 1;
	if (key == S_KEY)
		data->key_s = 1;
	if (key == D_KEY)
		data->key_d = 1;
	if (key == LEFT_ARROW)
		data->key_rotate_left = 1;
	if (key == RIGHT_ARROW)
		data->key_rotate_right = 1;
	return (1);
}

int	key_release(int key, t_data *data)
{
	if (key == ESCAPE)
		exit_game(data);
	if (key == W_KEY)
		data->key_w = 0;
	if (key == A_KEY)
		data->key_a = 0;
	if (key == S_KEY)
		data->key_s = 0;
	if (key == D_KEY)
		data->key_d = 0;
	if (key == LEFT_ARROW)
		data->key_rotate_left = 0;
	if (key == RIGHT_ARROW)
		data->key_rotate_right = 0;
	return (1);
}

int	game_update(t_data *data)
{
	player_move(data, data->raycast);
	raycasting(data, data->raycast);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->ptr_img->img, 0, 0);
	return (1);
}

void	game_loop(t_data *data)
{
	mlx_hook(data->mlx->win, 17, 1L << 2, &exit_game, data);
	mlx_hook(data->mlx->win, 2, 1L << 0, &key_press, data);
	mlx_hook(data->mlx->win, 3, 1L << 1, &key_release, data);
	mlx_loop_hook(data->mlx->mlx, &game_update, data);
	mlx_loop(data->mlx->mlx);
}
