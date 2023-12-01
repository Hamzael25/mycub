/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/01 19:12:43 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/01 19:15:24 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	key_press_hook(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65365)
		data->play->key_states[keycode] = true;
	return (0);
}

int	key_release_hook(int keycode, t_data *data)
{
	if (keycode >= 0 && keycode < 65365)
		data->play->key_states[keycode] = false;
	return (0);
}
