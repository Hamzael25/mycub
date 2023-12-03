/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_v.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:21:23 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/02 16:24:23 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	check_vertical_line(t_stage *s, t_data *d)
{
	looking_vertical(s, d);
	init_vertical(s, d);
	while (s->dof < d->parse->biger)
	{
		s->mx = (int)(s->rx / TILE_SIZE);
		s->my = (int)(s->ry / TILE_SIZE);
		if (s->mx >= 0 && s->mx < d->parse->wmap && s->my >= 0
			&& s->my < d->parse->hmap
			&& s->mx < (int)ft_strlen(d->parse->map[s->my])
			&& s->my < (int)ft_tablen(d->parse->map)
			&& d->parse->map[s->my][s->mx] == '1')
		{
			s->vx = s->rx;
			s->vy = s->ry;
			s->dis_v = dist(d->play->posx, d->play->posy, s->vx, s->vy);
			break ;
		}
		else
		{
			s->rx += s->xo;
			s->ry += s->yo;
			s->dof += 1;
		}
	}
}

void	init_vertical(t_stage *s, t_data *d)
{
	s->dof = 0;
	s->vx = d->play->posx;
	s->vy = d->play->posy;
	s->dis_v = 1000000;
}

void	looking_vertical(t_stage *stage, t_data *data)
{
	float	n_tan;

	n_tan = -tan(stage->ra);
	if (stage->ra > PI / 2 && stage->ra < 3 * PI / 2)
	{
		stage->rx = (float)(((int)data->play->posx / TILE_SIZE) * \
		TILE_SIZE) - 0.0001;
		stage->ry = (data->play->posx - stage->rx) * n_tan + data->play->posy;
		stage->xo = -TILE_SIZE;
		stage->yo = -stage->xo * n_tan;
	}
	else if (stage->ra < PI / 2 || stage->ra > 3 * PI / 2)
	{
		stage->rx = (float)(((int)data->play->posx / TILE_SIZE) * \
		TILE_SIZE) + TILE_SIZE;
		stage->ry = (data->play->posx - stage->rx) * n_tan + data->play->posy;
		stage->xo = TILE_SIZE;
		stage->yo = -stage->xo * n_tan;
	}
	else
	{
		stage->rx = data->play->posx;
		stage->ry = data->play->posy;
		stage->dof = data->parse->biger;
	}
}
