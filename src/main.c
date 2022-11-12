#include "../cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	data = (t_data){};
	if (argc != 2)
		clean_exit(&data, -1, 2, "Usage: \"./cub3D map_file.cub\"\n");
	init_data(&data);
	init_mlx(&data);
	init_map(&data, argv[1]);
	read_file(&data, argv[1]);
	game_launcher(&data);
	game_loop(&data);

	return (0);
}