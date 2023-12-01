/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:19:56 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/01 21:32:22 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	check_wall(t_parse *parse, int i, int j, int save)
{
	save = nb_of_space(parse->map, &i);
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == '0' && (i == save || !parse->map[i - 1][j] \
			|| parse->map[i - 1][j] == '\n' || !parse->map[i + 1][j] || \
			parse->map[i + 1][j] == '\n' || parse->map[i + 1][j] == 'x' || \
			!parse->map[i][j + 1] || parse->map[i][j + 1] == '\n' || \
			(j > 0 && (!parse->map[i][j - 1]
				|| parse->map[i][j - 1] == '\n'))))
				return (1);
			else if (parse->map[i][j] == 'x')
			{
				if ((parse->map[i + 1] && parse->map[i + 1][j] == '0') || \
				(j > 0 && parse->map[i][j - 1] == '0') || \
				(parse->map[i][j + 1] && parse->map[i][j + 1] == '0'))
					return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	check_player(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (is_player(map[i][j]) && ((map[i][j + 1]
				&& map[i][j + 1] == '\n')
				|| !map[i][j - 1] || !map[i + 1][j]
				|| !map[i - 1][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	check_map(char **map)
{
	size_t	i;

	i = 0;
	if (!map[0])
		return (1);
	while (map[i] && map[i][0] == '\n')
		i++;
	while (map[i] && map[i][0] == 'x')
		i++;
	while (map[i] && (map[i][0] == '1' || map[i][0] == 'x'))
		i++;
	if (map[i - 1][ft_strlen(map[i - 1]) - 1] == '\n')
		return (1);
	return (0);
}

int	check_path(t_data *data)
{
	if (check_open_file(data, data->parse->no, 0)
		|| check_open_file(data, data->parse->so, 0)
		|| check_open_file(data, data->parse->ea, 0)
		|| check_open_file(data, data->parse->we, 0))
		return (1);
	return (0);
}
