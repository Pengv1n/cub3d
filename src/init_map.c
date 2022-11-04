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
			;
		}
		if (*line != '1' && *line != ' ')
		{
			free(line);
			;
		}
		data->y_max++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	data->map = ft_calloc(data->y_max + 1, sizeof(char *));
	if (!data->map)
		;
}

void	init_map_norme(t_data *data, char *line, int fd)
{
	if (line)
		free(line);
	close(fd);
	if (!data->map)
		;
}

void	init_map(t_data *data, char *path)
{
	int	fd;
	int	i;
	char	*line;

	fd = open_file(path);
	if (fd < 0)
		;
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		while (line[i] == ' ')
			i++;
		if (line[i] == '1')
		{
			free(line);
			line = NULL;
			alloc_map(data, fd);
			break;
		}
		free(line);
		line = get_next_line(fd);
	}
	init_map_norme(data, line, fd);
}