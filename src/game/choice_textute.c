#include "../../cub3d.h"

int	trgb_convert(int t, int r, int g, int b)
{
	int	color;

	color = t << 24;
	color |= r << 16;
	color |= g << 8;
	color |= b;
	return (color);
}

int	choice_texture(int side)
{
	if (side == 0)
		return (SO_WALL);
	else if (side == 1)
		return (EA_WALL);
	else if (side == 2)
		return (NO_WALL);
	return (WE_WALL);
}