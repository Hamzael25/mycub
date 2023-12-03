/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:00:37 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/02 16:25:42 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	ray_cast(t_data *data, t_stage *stage)
{
	int		r;

	stage->ra = data->play->pa - DR * TILE_SIZE;
	r = -1;
	while (++r < WINWIDTH)
	{
		check_horizontal_line(stage, data);
		check_vertical_line(stage, data);
		choose_line(stage);
		draw_stage(data, stage, r, stage->ra);
		stage->ra += DR * (FOV_ANGLE / WINWIDTH);
		if (stage->ra < 0)
			stage->ra += 2 * PI;
		if (stage->ra > 2 * PI)
			stage->ra -= 2 * PI;
	}
}

void	check_horizontal_line(t_stage *s, t_data *d)
{
	init_horizontal(s, d);
	looking_horizontal(s, d);
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
			s->hx = s->rx;
			s->hy = s->ry;
			s->dis_h = dist(d->play->posx, d->play->posy, s->hx, s->hy);
			s->dof = d->parse->biger;
		}
		else
		{
			s->rx += s->xo;
			s->ry += s->yo;
			s->dof += 1;
		}
	}
}

void	init_horizontal(t_stage *s, t_data *d)
{
	s->dof = 0;
	s->dis_h = 100000000;
	s->hx = d->play->posx;
	s->hy = d->play->posy;
}

void	looking_horizontal(t_stage *stage, t_data *d)
{
	float	a_tan;

	a_tan = -1 / tan(stage->ra);
	if (stage->ra > PI)
	{
		stage->ry = (float)(((int)d->play->posy / TILE_SIZE) * \
		TILE_SIZE) - 0.0001;
		stage->rx = (d->play->posy - stage->ry) * a_tan + d->play->posx;
		stage->yo = -TILE_SIZE;
		stage->xo = -stage->yo * a_tan;
	}
	else if (stage->ra < PI)
	{
		stage->ry = (float)(((int)d->play->posy / TILE_SIZE) * \
		TILE_SIZE) + TILE_SIZE;
		stage->rx = (d->play->posy - stage->ry) * a_tan + d->play->posx;
		stage->yo = TILE_SIZE;
		stage->xo = -stage->yo * a_tan;
	}
	else
	{
		stage->rx = d->play->posx;
		stage->ry = d->play->posy;
		stage->dof = d->parse->biger;
	}
}

void	choose_line(t_stage *stage)
{
	stage->h_redded = 1;
	if (stage->dis_v < stage->dis_h)
	{
		stage->rx = stage->vx;
		stage->ry = stage->vy;
		stage->dist = stage->dis_v;
		stage->h_redded = 0;
	}
	else
	{
		stage->rx = stage->hx;
		stage->ry = stage->hy;
		stage->dist = stage->dis_h;
	}
}
