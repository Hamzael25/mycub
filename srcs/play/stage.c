/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stage.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 16:27:24 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/02 20:56:37 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	draw_stage(t_data *data, t_stage *stage, int r, float ra)
{
	float		scale_factor;
	t_sprite	*tmp_sprite;

	define_which_sprite(data, &tmp_sprite, ra);
	scale_factor = (float) tmp_sprite->width / 32.0;
	stage->ca = data->play->pa - ra;
	if (stage->ca < 0)
		stage->ca += 2 * PI;
	if (stage->ca > 2 * PI)
		stage->ca -= 2 * PI;
	stage->dist = stage->dist * cos(stage->ca);
	stage->line_h = (46 * WINHEIGHT) / stage->dist;
	stage->ty_step = (float)tmp_sprite->height / (float)stage->line_h;
	stage->ty_step /= scale_factor;
	stage->ty_off = 0;
	if (stage->line_h > WINHEIGHT)
	{
		stage->ty_off = (stage->line_h - WINHEIGHT) / 2.0;
		stage->line_h = WINHEIGHT;
	}
	stage->line_off = WINHEIGHT / 2 - (stage->line_h / 2);
	stage->ty = stage->ty_off * stage->ty_step;
	stage->tx = 0;
	draw_sprites(data, r, ra);
}

void	draw_sprites(t_data *data, int r, float ra)
{
	t_sprite	*sprite;

	draw_s_and_n_sprite(data, ra, &sprite);
	draw_e_and_w_sprite(data, ra, &sprite);
	put_sprite(sprite, data, r);
}

void	draw_s_and_n_sprite(t_data *data, float ra, t_sprite **sprite)
{
	if (data->stage->h_redded)
	{
		if (ra >= 0 && ra < PI)
		{
			*sprite = data->so_text;
			data->stage->tx = (int)data->stage->rx % TILE_SIZE;
			data->stage->tx = (TILE_SIZE - 1) - data->stage->tx;
		}
		else
		{
			*sprite = data->no_text;
			data->stage->tx = TILE_SIZE - \
			((int)data->stage->rx % TILE_SIZE) - 1;
			data->stage->tx = (TILE_SIZE - 1) - data->stage->tx;
		}
	}
}

void	draw_e_and_w_sprite(t_data *data, float ra, t_sprite **sprite)
{
	if (!data->stage->h_redded)
	{
		if (ra >= PI / 2 && ra < 3 * PI / 2)
		{
			*sprite = data->we_text;
			data->stage->tx = TILE_SIZE - \
			((int)data->stage->ry % TILE_SIZE) - 1;
		}
		else
		{
			*sprite = data->ea_text;
			data->stage->tx = (int)data->stage->ry % TILE_SIZE;
		}
	}
}

void	put_sprite(t_sprite *sprite, t_data *data, int r)
{
	int		i;
	float	c;
	float	scale;

	scale = (float) sprite->width / 32.0;
	i = -1;
	while (++i < data->stage->line_off)
		put_pixel(data->win, r, i, data->parse->color_ceiling_hexa);
	i--;
	while (++i < data->stage->line_h + data->stage->line_off)
	{
		c = *(int *)(sprite->addr + (int)(data->stage->ty * scale) \
			* sprite->line_length + (int)(data->stage->tx * scale) \
			* (sprite->bits_per_pixel / 8));
		put_pixel(data->win, r, i, c);
		data->stage->ty += data->stage->ty_step;
	}
	i--;
	while (++i < WINHEIGHT)
		put_pixel(data->win, r, i, data->parse->color_floor_hexa);
}
