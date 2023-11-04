/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 09:53:15 by hel-ouar         ###   ########.fr       */
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
