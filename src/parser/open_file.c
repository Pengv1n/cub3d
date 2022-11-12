#include "../../cub3d.h"

int	check_extension(char *path, const char *type)
{
	int	i;

	i = 0;
	if (ft_strlen(path) < 5)
		return (1);
	while (path[i] && path[i + 4] != '\0')
		i++;
	if (!ft_strncmp(path + i, type, 4))
		return (1);
	return (0);
}

int	open_file(char *path)
{
	int	fd;

	if (!check_extension(path, ".cub"))
		return (-1);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (-1);
	return (fd);
}