/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/26 16:00:36 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_color(char **split_color, char *color, int i, int nb)
{
	if (color[0] == ',' || color[ft_strlen(color) - 2] == ',')
		return (1);
	while (color[i] != '\n')
	{
		if (color[i] == ',' && color[i + 1] && color[i + 1] == ',')
			return (1);
		else if ((color[i] == ',' && color[i + 1] != ',' && color[i + 1]))
		{
			i++;
			continue ;
		}
		else if (!ft_isdigit(color[i]))
			return (1);
		i++;
	}
	i = -1;
	while (split_color[++i])
	{
		nb = ft_atoi(split_color[i]);
		if (nb < 0 || nb > 255)
			return (1);
	}
	if (i != 3)
		return (1);
	return (0);
}
