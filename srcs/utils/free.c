/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/26 16:00:26 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	free_struct(t_data *data);
void	free_parse(t_parse *parse);

void	ft_free_all(t_data *data)
{
	free_struct(data);
	free_parse(data->parse);
}

void	free_struct(t_data *data)
{
	if (data->parse)
		free(data->parse);
	if (data->play)
		free(data->play);
}

void	free_parse(t_parse *parse)
{
	if (parse)
	{
		if (parse->no)
			free(parse->no);
		if (parse->so)
			free(parse->so);
		if (parse->ea)
			free(parse->ea);
		if (parse->we)
			free(parse->we);
		if (parse->map)
			ft_free_tab(parse->map);
	}
}
