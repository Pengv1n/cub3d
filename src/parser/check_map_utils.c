/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranuytte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/06 13:30:06 by ranuytte          #+#    #+#             */
/*   Updated: 2022/11/12 19:58:30 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

int	check_empty_spaces(t_data *data, int i, int j)
{
	int	prev_size;

	if (i < 1)
		return (0);
	prev_size = ft_strlen(data->map[i - 1]) - 1;
	if (prev_size < j)
	{
		while (data->map[i][prev_size + 1] != '\n' &&
				data->map[i][prev_size + 1] != '\0')
		{
			if (data->map[i][prev_size + 1] != '1')
				return (1);
			prev_size++;
		}
	}
	if (prev_size > j)
	{
		while (data->map[i - 1][j] != '\n')
		{
			if (data->map[i - 1][j] != '1')
				return (1);
			j++;
		}
	}
	return (0);
}
