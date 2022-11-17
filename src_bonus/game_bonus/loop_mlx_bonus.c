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

#include "../../Include_bonus//cub3d_bonus.h"

int	exit_game(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
		mlx_destroy_image(data->mlx->mlx, data->txts[i].img);
	mlx_destroy_image(data->mlx->mlx, data->ptr_img->img);
	mlx_clear_window(data->mlx->mlx, data->mlx->win);
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

void	print_y(char *map)
{
	int	i;

	i = -1;
	while (map[++i])
	{
		if (map[i] == '0')
			write(1, "\e[42m0", 6);
		else if (map[i] == '1')
			write(1, "\e[0;101m1", 9);
		else
		{
			char *t = ft_strjoin("\e[0m", &map[i]);
			write(1, t, 5);
		}
	}
}

void	print_map(t_data *data)
{
	int	i;

	i = -1;
	int	x_pos = (int)data->player_pos_x;
	int	y_pos = (int)data->player_pos_y;
	char **map = data->map;
	while (map[++i])
	{
		print_y(map[i]);
	}
}

int	game_update(t_data *data)
{
	player_move(data, data->raycast);
	raycasting(data, data->raycast);
	map2d(data);
	mlx_put_image_to_window(data->mlx->mlx, data->mlx->win,
		data->ptr_img->img, 0, 0);
	print_map(data);
	write(1, "\n", 1);
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
