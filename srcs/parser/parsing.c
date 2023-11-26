/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/26 16:00:16 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int check_file(char *map, char *ext);
int check_open_file(t_data *data, char *file, int flg);

int	parsing(char *map, t_data *data)
{
	if (check_file(map, "buc.") || check_open_file(data, map, 1))
		return (1);
	return (0);
}

int check_file(char *map, char *ext)
{
	char **tmp;
	char *filename;

	tmp = ft_split(map, '/');
	if (!tmp)
		return (ft_free_tab(tmp), 1);
	filename = tmp[ft_strlen_dtab(tmp) - 1];
	while (*filename)
		filename++;
	filename--;
	while (*filename == *ext)
	{
		filename--;
		ext++;
	}
	if (*ext)
		return (ft_putstr_fd("Error\nWrong extension\n", 2), \
			ft_free_tab(tmp), 1);
	return (ft_free_tab(tmp), 0);
}

int	check_open_file(t_data *data, char *file, int flg)
{
	int	fd;

	if (access(file, F_OK) != -1)
	{
		if (access(file, R_OK) == -1)
			return (ft_putstr_fd("Error\nPemission File\n", 2), 1);
	}
	else
		return (ft_putstr_fd("Error\nFile not Found\n", 2), 1);
	fd = open(file, O_RDONLY);
	if (fd < 1)
		return (ft_putstr_fd("Error\nfailed to open file\n", 2), 1);
	if (flg)
	{
		if (check_valid_file(data->parse, fd))
			return (1);
	}
	return (0);
}
