/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 11:44:47 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 09:24:43 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3D.h"

t_get_map	*lstlast(t_get_map *lst)
{
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

t_get_map	*create_cell(char *line)
{
	t_get_map	*cell;

	cell = malloc(sizeof(t_get_map));
	if (!cell)
		return (NULL);
	cell->line = ft_strdup(line);
	cell->next = NULL;
	return (cell);
}

void	ft_lstad_back(t_get_map **lst, t_get_map *new)
{
	t_get_map	*last;

	if (lst)
	{
		if (*lst)
		{
			last = lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

int	lstsize(t_get_map *lst)
{
	int			i;
	t_get_map	*cpy;

	cpy = lst;
	i = 0;
	while (cpy)
	{
		cpy = cpy->next;
		i++;
	}
	return (i);
}

void	lstclear(t_get_map **lst)
{
	t_get_map	*tmp;

	if (lst)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			free((*lst)->line);
			free(*lst);
			*lst = tmp;
		}
	}
}
