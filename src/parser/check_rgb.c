#include "../../cub3d.h"

int	substitute_coma(char *line)
{
	int	i;
	int	nb_coma;

	nb_coma = 0;
	i = 0;
	while (line[i])
	{
		if (line[i] == ',')
		{
			nb_coma++;
			line[i] = ' ';
		}
		if (line[i] == '\n')
			line[i] = ' ';
		i++;
	}
	if (nb_coma != 2)
		return (1);
	return (0);
}

int	check_rgb(t_elem *elem)
{
	int	i;

	i = -1;
	while (++i < 3)
		if (elem->rgb[i] < 0 || elem->rgb[i] > 255)
			return (1);
	return (0);
}

int	get_int_value(t_elem *elem, char **split)
{
	int	i;
	int	j;

	i = 0;
	while (split[i + 1])
	{
		j = 0;
		while (split[i + 1][j])
		{
			if (!ft_isdigit((int)split[i + 1][j]))
				return (1);
			j++;
		}
		elem->rgb[i] = ft_atoi(split[i + 1]);
		j = 0;
		i++;
	}
	if (i != 3 || check_rgb(elem))
		return (1);
	return (0);
}

int	check_nb_element_rgb(char **info)
{
	int	i;

	i = 0;
	while (info[i])
		i++;
	if (i != 4)
		return (1);
	return (0);
}