/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:59:14 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:59:15 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

int	skip_spaces(char **line)
{
	while (**line == ' ')
		(*line)++;
	return (0);
}

void	clean_free_tmp_split(char *tmp, char **split)
{
	if (tmp)
	{
		free(tmp);
		tmp = NULL;
	}
	if (split)
	{
		free_split(split);
		split = NULL;
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s2[i])
	{
		if (s1[i] != s2[i])
			return (1);
		i++;
	}
	if (s1[i] != s2[i])
		return (1);
	return (0);
}

int	check_texture_path(t_elem *txt, char *path)
{
	int	i;

	if (!path)
		return (1);
	i = 0;
	while (ft_isprint(path[i]))
		i++;
	if (path[i] != '\0')
		ft_memmove(path + i, path + (i + 1), 1);
	if (check_extension(path, ".xpm"))
		txt->type = XPM;
	else if (check_extension(path, ".png"))
		txt->type = PNG;
	if (!txt->type)
		return (0);
	return (1);
}
