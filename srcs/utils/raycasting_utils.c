/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:26:01 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/02 20:58:00 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

float	dist(float ax, float ay, float bx, float by)
{
	return (sqrt((bx - ax) * (bx - ax) + (by - ay) * (by - ay)));
}

void	put_pixel(t_win *draw, int x, int y, int color)
{
	if ((x >= 0 && x < 1920) && (y >= 0 && y < 1080))
		((int *)draw->addr)[y * (draw->line_length >> 2) + x] = color;
}

void	define_which_sprite(t_data *data, t_sprite **sprite, float ra)
{
	if (data->stage->h_redded)
	{
		if (ra >= 0 && ra < PI)
			*sprite = data->so_text;
		else
			*sprite = data->no_text;
	}
	else
	{
		if (ra >= PI / 2 && ra < 3 * PI / 2)
			*sprite = data->we_text;
		else
			*sprite = data->ea_text;
	}
}
