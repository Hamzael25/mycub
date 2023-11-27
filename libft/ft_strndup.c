/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 15:08:57 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/27 02:01:49 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(char *s, size_t n)
{
	char	*new;

	new = malloc(n + 1);
	if (!new)
		return (NULL);
	ft_strncpy(new, s, n);
	return (new[n] = '\0', new);
}
