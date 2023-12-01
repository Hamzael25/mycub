/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 14:30:17 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/12/01 23:08:36 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_test(char const *s, unsigned int start, size_t len, char *final)
{
	size_t	i;

	i = 0;
	while (s[start] && i < len)
	{
		final[i] = s[start];
		i++;
		start++;
	}
	final[i] = 0;
	return (final);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*final;

	if (!s)
		return (NULL);
	else if (start >= ft_strlen(s))
	{
		final = malloc(sizeof(char));
		if (!final)
			return (NULL);
		final[0] = 0;
		return (final);
	}
	else if (len > ft_strlen(s + start))
	{
		final = malloc(sizeof(char) * ft_strlen(s + start) + 1);
		if (!final)
			return (NULL);
		return (ft_test(s, start, len, final));
	}
	final = malloc(sizeof(char) * len + 1);
	if (!final)
		return (NULL);
	return (ft_test(s, start, len, final));
}
