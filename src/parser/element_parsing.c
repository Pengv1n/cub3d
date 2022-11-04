#include "../../cub3d.h"

int	check_identifier(t_data *data, chec *line, char ***split)
{
	if ()
}

int	element_parsing(t_data *data, int fd)
{
	char	**split;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	tmp = line;
	while (!skip_spaces(&line) && *line == '\n')
	{
		free(tmp);
		tmp = NULL;
		line = get_next_line(fd);
		tmp = line;
	}
	split = NULL;
	if ()
}