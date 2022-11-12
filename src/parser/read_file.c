#include "../../cub3d.h"

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