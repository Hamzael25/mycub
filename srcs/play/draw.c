/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 17:02:28 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/03 17:28:57 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_map_view(t_data *data, int i, int j, int x)
{
	int	startx;
	int	starty;
	int	y;

	set_initial_player_position(data, &startx, &starty);
	y = 0;
	i = starty - 1;
	while (++i < starty + 10 && i < data->parse->hmap)
	{
		x = 0;
		j = startx - 1;
		while (++j < startx + 10 && j < data->parse->wmap
			&& j < (int)ft_strlen(data->parse->map[i]))
		{
			draw_tile(data, data->parse->map[i][j], x, y);
			x += TILE_SIZE;
		}
		y += TILE_SIZE;
	}
	update_player_spawn(data);
}

void	set_initial_player_position(t_data *data, int *startx, int *starty)
{
	*startx = (int)data->play->posx / TILE_SIZE - 10 / 2;
	*starty = (int)data->play->posy / TILE_SIZE - 10 / 2;
	if (*startx < 0)
		*startx = 0;
	if (*starty < 0)
		*starty = 0;
}

void	draw_tile(t_data *data, char map_val, int x, int y)
{
	if (map_val == '1')
		render_wall_tile(data, H_BLACK, x, y);
	else if (map_val == '0')
		render_wall_tile(data, H_WHITE, x, y);
	else if (is_player(map_val))
		render_wall_tile(data, H_PINK, x, y);
}

void	update_player_spawn(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (data->parse->map[++i])
	{
		j = -1;
		while (data->parse->map[i][++j])
		{
			if (data->parse->map[i][j] == 'N')
				data->parse->map[i][j] = '0';
		}
	}
	data->parse->map[(int)data->play->posy / TILE_SIZE] \
		[(int)data->play->posx / TILE_SIZE] = 'N';
}

void	render_wall_tile(t_data *data, int color, int x, int y)
{
	int	i;
	int	j;
	int	save;

	save = x;
	i = 0;
	while (i < TILE_SIZE)
	{
		j = 0;
		x = save;
		while (j < TILE_SIZE)
		{
			if (j == 0 || j == 31 || i == 31 || i == 0)
				put_pixel(data->win, x, y, H_GREY);
			else
				put_pixel(data->win, x, y, color);
			j++;
			x++;
		}
		y++;
		i++;
	}
}
