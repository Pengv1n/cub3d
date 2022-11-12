/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:58:58 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:59:00 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3d.h"

char	*skip_newline(int fd)
{
	char	*line;
	char	**split;

	line = get_next_line(fd);
	split = ft_split(line, ' ');
	while (**split == '\n')
	{
		free(line);
		free_split(split);
		line = get_next_line(fd);
		split = ft_split(line, ' ');
	}
	if (split)
		free_split(split);
	return (line);
}

int	save_line(t_data *data, char *line)
{
	static int	y;
	int			i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1' && line[i] != '0' && line[i] != ' '
			&& line[i] != 'N' && line[i] != 'S' && line[i] != 'E'
			&& line[i] != 'W' && line[i] != '\n')
			return (1);
		i++;
	}
	data->map[y] = ft_strdup(line);
	y++;
	return (0);
}

int	map_parsing(t_data *data, int fd)
{
	char	*line;

	line = skip_newline(fd);
	while (line)
	{
		if (save_line(data, line))
		{
			free(line);
			return (1);
		}
		free(line);
		line = get_next_line(fd);
	}
	if (check_map(data))
		return (1);
	return (0);
}
