/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/02 15:49:06 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/02 18:32:28 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	move(t_data *data)
{
	float	move_speed;
	float	rotate_speed;
	float	collision_margin;
	float	newx;
	float	newy;

	move_speed = 0.6;
	rotate_speed = 0.04;
	collision_margin = 6.0;
	newx = data->play->posx;
	newy = data->play->posy;
	check_key_and_set_new_position(data, move_speed, &newx, &newy);
	check_collision(data, newx, newy, collision_margin);
	check_key_and_set_new_angle(data, rotate_speed);
	check_esc_key(data);
}

void	check_key_and_set_new_position(t_data *data, float moveSpeed, \
float *newX, float *newY)
{
	if (data->play->key_states[W])
	{
		*newX += data->play->px * moveSpeed;
		*newY += data->play->py * moveSpeed;
	}
	if (data->play->key_states[S])
	{
		*newX -= data->play->px * moveSpeed;
		*newY -= data->play->py * moveSpeed;
	}
	if (data->play->key_states[A])
	{
		*newX -= cos(data->play->pa + PI / 2) * moveSpeed * 3;
		*newY -= sin(data->play->pa + PI / 2) * moveSpeed * 3;
	}
	if (data->play->key_states[D])
	{
		*newX += cos(data->play->pa + PI / 2) * moveSpeed * 3;
		*newY += sin(data->play->pa + PI / 2) * moveSpeed * 3;
	}
}

void	check_collision(t_data *data, float newX, float newY, \
float c_margin)
{
	if (!is_collision(data, newX, data->play->posy) && \
	!is_collision(data, newX - c_margin, data->play->posy - c_margin) && \
	!is_collision(data, newX - c_margin, data->play->posy + c_margin) && \
	!is_collision(data, newX + c_margin, data->play->posy - c_margin) && \
	!is_collision(data, newX + c_margin, data->play->posy + c_margin))
		data->play->posx = newX;
	if (!is_collision(data, data->play->posx, newY) && \
	!is_collision(data, data->play->posx - c_margin, newY - c_margin) && \
	!is_collision(data, data->play->posx - c_margin, newY + c_margin) && \
	!is_collision(data, data->play->posx + c_margin, newY - c_margin) && \
	!is_collision(data, data->play->posx + c_margin, newY + c_margin))
		data->play->posy = newY;
}

void	check_key_and_set_new_angle(t_data *data, float rotateSpeed)
{
	if (data->play->key_states[RIGHT])
	{
		data->play->pa += rotateSpeed;
		if (data->play->pa > 2 * PI)
			data->play->pa -= 2 * PI;
		data->play->px = cos(data->play->pa) * 5;
		data->play->py = sin(data->play->pa) * 5;
	}
	if (data->play->key_states[LEFT])
	{
		data->play->pa -= rotateSpeed;
		if (data->play->pa < 0)
			data->play->pa += 2 * PI;
		data->play->px = cos(data->play->pa) * 5;
		data->play->py = sin(data->play->pa) * 5;
	}
}

void	check_esc_key(t_data *data)
{
	if (data->play->key_states[ESC])
	{
		ft_free_all(data, 1);
		exit(0);
	}
}
