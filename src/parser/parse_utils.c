#include "../../cub3d.h"

void	skip_spaces(char **line)
{
	while (**line == ' ')
		(*line)++;
	return (0);
}