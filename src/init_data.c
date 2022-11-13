/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:17 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:19 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	init_elem(t_data *data)
{
	data->elem[0].id = ft_strdup("NO");
	data->elem[0].path = NULL;
	data->elem[1].id = ft_strdup("SO");
	data->elem[1].path = NULL;
	data->elem[2].id = ft_strdup("WE");
	data->elem[2].path = NULL;
	data->elem[3].id = ft_strdup("EA");
	data->elem[3].path = NULL;
	data->elem[4].id = ft_strdup("F");
	data->elem[4].path = NULL;
	data->elem[5].id = ft_strdup("C");
	data->elem[5].path = NULL;
}

void	init_data(t_data *data)
{
	int	i;

	init_elem(data);
	data->mlx = malloc(sizeof(t_mlx));
	data->ptr_img = malloc(sizeof(t_img));
	data->raycast = malloc(sizeof(t_raycast));
	if (!data->mlx || !data->ptr_img || !data->raycast)
		clean_exit(data, -1, 2, "Error: init data failed\n");
	*(data)->raycast = (t_raycast){};
	data->width_screen = 1920;
	data->height_screen = 1040;
	i = -1;
	while (++i < 4)
		data->txts[i] = (t_txt){};
}
