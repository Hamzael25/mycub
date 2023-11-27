/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 02:18:05 by hamzaelouar       #+#    #+#             */
/*   Updated: 2023/11/27 02:18:06 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

int	is_space(char *str)
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

int	nb_of_space(char **str, int *i)
{
	int	cpt;

	cpt = 0;
	while (is_space(str[*i]))
	{
		(*i)++;
		cpt++;
	}
	return (cpt);
}
