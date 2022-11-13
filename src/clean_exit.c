/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:55:58 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:55:59 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Include/cub3d.h"

void	clean_exit(t_data *data, int fd_gnl, int fd, char *msg)
{
	char	*line;

	if (fd_gnl >= 0)
	{
		line = get_next_line(fd_gnl);
		while (line)
		{
			if (line)
				free(line);
			line = get_next_line(fd_gnl);
		}
		free(line);
	}
	if (data->mlx)
	{
		mlx_clear_window(data->mlx->mlx, data->mlx->win);
		mlx_destroy_window(data->mlx->mlx, data->mlx->win);
	}
	free_all(data);
	ft_putstr_fd(msg, fd);
	exit(fd);
}
