#include "../cub3d.h"
#include "../libft/libft.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = NULL;
	if (argc != 2)
		;
	init_data(&data);
	init_mlx(&data);
	init_map(&data, argv[1]);

	return (0);
}