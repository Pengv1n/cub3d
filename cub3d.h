#ifndef CUB3D_CUB3D_H
#define CUB3D_CUB3D_H

#include "stdio.h"
#include "libft/libft.h"
#include "minilibx/mlx.h"
typedef	struct	s_mlx
{
	void	*ptr;
}	t_mlx;

typedef	struct	s_all
{
	t_mlx	mlx;
}	t_all;

int	ft_namecheck(char *argv, char *ext);

#endif //CUB3D_CUB3D_H
