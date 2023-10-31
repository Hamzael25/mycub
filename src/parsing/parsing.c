/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/10/31 11:55:19 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

int check_map(char *map, char *ext)
{
	char **tmp;
	char *filename;

	tmp = ft_split(map, '/');
	if (!tmp)
		return (ft_free_tab(tmp), 1);
	filename = tmp[ft_strlen_dtab(tmp)];
	while (*filename)
		filename++;
	filename--;
	
	
}
int	parsing(char *map)
{
	
}