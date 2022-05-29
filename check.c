#include "cub3d.h"

int	ft_namecheck(char *argv, char *ext)
{
	int	len;

	len = ft_strlen(argv);
	if (len > 4 && argv[len - 1] == ext[2] && argv[len - 2] == ext[1]
		&& argv[len - 3] == ext[0] && argv[len - 4] == '.')
		return (1);
	return (0);
}