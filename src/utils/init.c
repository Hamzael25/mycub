/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 08:55:42 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int	init_struct(t_data *data)
{
	data->parse = ft_calloc(1, sizeof(t_parse));
	data->play = ft_calloc(1, sizeof(t_play));
	if (!data->parse || !data->play)
		return (0);
	ft_bzero(data->parse, sizeof(t_parse));
	ft_bzero(data->play, sizeof(t_play));
	return (1);
}
