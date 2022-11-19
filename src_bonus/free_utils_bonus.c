/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:07 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:09 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include_bonus/cub3d_bonus.h"

void	free_map(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->y_max)
	{
		free(data->map[i]);
		data->map[i] = NULL;
		i++;
	}
	free(data->map);
	data->map = NULL;
}

void	free_texture(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 4)
	{
		if (data->txts[i].txt)
			free(data->txts[i].txt);
	}
}

void	free_elem(t_data *data)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (data->elem[i].id)
			free(data->elem[i].id);
		if (data->elem[i].path)
			free(data->elem[i].path);
	}
}

void	free_all(t_data *data)
{
	if (data->map)
		free_map(data);
	if (data->mlx)
	{
		free(data->mlx->mlx);
		free(data->mlx);
	}
	if (data->ptr_img)
		free(data->ptr_img);
	if (data->raycast)
		free(data->raycast);
	free_texture(data);
	free_elem(data);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
