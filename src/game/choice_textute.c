/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   choice_textute.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aregenia <aregenia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 19:56:54 by aregenia          #+#    #+#             */
/*   Updated: 2022/11/12 19:56:56 by aregenia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Include/cub3d.h"

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
		return (NO_WALL);
	else if (side == 1)
		return (EA_WALL);
	else if (side == 2)
		return (SO_WALL);
	return (WE_WALL);
}
