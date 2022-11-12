#include "../../cub3d.h"

int	check_nb_element_texture(char **info)
{
	if (!info[1])
		return (1);
	if (info[2] && *info[2] != '\n')
		return (1);
	return (0);
}

int	identify(char *line)
{
	int	i;

	i = 0;
	while (line[i] == ' ')
		i++;
	if (line[i] == 'F' || line[i] == 'C')
		if (substitute_coma(line))
			return (1);
	return (0);
}

int	check_duplicate(t_data *data, char **sp)
{
	int	i;

	i = -1;
	while (++i < 6)
	{
		if (!ft_strcmp(data->elem[i].id, sp[0]))
		{
			if (data->elem[i].path)
				return (1);
			if (*(data->elem[i]).id == 'F'|| *(data->elem[i]).id == 'C')
			{
				if (get_int_value(&(data)->elem[i], sp))
					return (1);
				data->elem[i].path = ft_strdup("FILLED");
				return (0);
			}
			else if (check_texture_path(sp[1]))
			{
				data->elem[i].path = ft_strdup(sp[1]);
				return (0);
			}
		}
	}
	return (1);
}

int	check_identifier(t_data *data, char *line, char ***split)
{
	if (identify(line))
		return (1);
	*split = ft_split(line, ' ');
	if (**split[0] == 'N' || **split[0] == 'S' ||
		**split[0] == 'W' || **split[0] == 'E')
	{
		if (check_nb_element_texture(*split) || check_duplicate(data, *split))
			return (1);
		return (0);
	}
	if (**split[0] == 'F' || **split[0] == 'C')
	{
		if (check_nb_element_rgb(*split) || check_duplicate(data, *split))
			return (1);
		return (0);
	}
	return (1);
}

int	element_parsing(t_data *data, int fd)
{
	char	**split;
	char	*line;
	char	*tmp;

	line = get_next_line(fd);
	tmp = line;
	while (!skip_spaces(&line) && *line == '\n')
	{
		free(tmp);
		tmp = NULL;
		line = get_next_line(fd);
		tmp = line;
	}
	split = NULL;
	if (check_identifier(data, tmp, &split))
	{
		clean_free_tmp_split(tmp, split);
		return (1);
	}
	clean_free_tmp_split(tmp, split);
	return (0);
}