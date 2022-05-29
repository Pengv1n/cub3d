#include <stdio.h>
#include "cub3d.h"

void	ft_declare(t_all s, char *file, int bmp)
{

}

void	ft_init(char *file, int bmp)
{
	t_all	s;
	t_mlx	mlx;

	mlx.ptr = NULL;
	s.mlx = mlx;
	ft_declare(s, file, bmp);
}

int main(int argc, char **argv)
{
	if (ft_namecheck(argv[1], "cub"))
		ft_init(argv[1], 0);
	else
		write(2, "Error: Invalid arguments\n", 26);

	return (0);
}
