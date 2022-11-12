/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:24 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:26 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3d.h"

void	alloc_map(t_data *data, int fd)
{
	char	*line;

	line = get_next_line(fd);
	data->y_max++;
	while (line)
	{
		if (*line == '\n')
		{
			free(line);
			clean_exit(data, fd, 2, "Error: empty line in map\n");
		}
		if (*line != '1' && *line != ' ')
		{
			free(line);
			clean_exit(data, fd, 2, "Error: map is not the last element\n");
		}
		data->y_max++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->map = ft_calloc(data->y_max + 1, sizeof(char *));
	if (!data->map)
		clean_exit(data, fd, 2, "Error: malloc map failed\n");
}

void	init_map_norme(t_data *data, char *line, int fd)
{
	if (line)
		free(line);
	close(fd);
	if (!data->map)
		clean_exit(data, -1, 2, "Error: no map in file\n");
}

void	init_map(t_data *data, char *path)
{
	int		fd;
	int		i;
	char	*line;

	fd = open_file(path);
	if (fd < 0)
		clean_exit(data, fd, 2, "Error: open failed\n");
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		i = 0;
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			free(line);
			line = NULL;
			alloc_map(data, fd);
			break ;
		}
		free(line);
		line = get_next_line(fd);
	}
	init_map_norme(data, line, fd);
}
