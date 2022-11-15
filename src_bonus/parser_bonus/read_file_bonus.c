/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:59:20 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:59:22 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include_bonus/cub3d_bonus.h"

void	map(t_data *data, int fd)
{
	if (map_parsing(data, fd))
		clean_exit(data, fd, 2, "Error: invalid map\n");
}

void	element(t_data *data, int fd)
{
	if (element_parsing(data, fd))
		clean_exit(data, fd, 2, "Error: invalid identifier\n");
}

int	read_file(t_data *data, char *path)
{
	int	elem;
	int	fd;

	fd = open_file(path);
	if (fd < 0)
		clean_exit(data, fd, 2, "Error: open failed\n");
	elem = 0;
	while (elem != 6)
	{
		element(data, fd);
		elem++;
	}
	map(data, fd);
	close(fd);
	return (0);
}
