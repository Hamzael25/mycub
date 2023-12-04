/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:18:05 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/12/04 17:35:19 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	space_or_x(char *str)
{
	while (*str)
	{
		if (*str == 'x')
			str++;
		else if (*str == '\n')
			str++;
		else
			return (0);
	}
	return (1);
}

int	count_space(char **str, int *i)
{
	int	cpt;

	cpt = 0;
	while (space_or_x(str[*i]))
	{
		(*i)++;
		cpt++;
	}
	return (cpt);
}
