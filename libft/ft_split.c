/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:34:41 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/12/01 19:58:59 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s, char c)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == c || s[i] == '\0') == 0
			&& (s[i + 1] == c || s[i + 1] == '\0') == 1)
			j++;
		i++;
	}
	return (j + 1);
}

static int	ft_sizeword(const char *s, char c, int pos)
{
	int	count;

	count = 0;
	while (s[pos])
	{
		if (s[pos] == c)
			return (count + 1);
		pos++;
		count++;
	}
	return (count + 1);
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * ft_countword(s, c));
	if (!tab)
		return (NULL);
	while (s[k] && i < ft_countword(s, c) - 1)
	{
		while (s[k] == c)
			k++;
		tab[i] = (char *)malloc(sizeof(char) * ft_sizeword(s, c, k));
		if (!tab[i])
			return (NULL);
		j = 0;
		while (s[k] && s[k] != c)
			tab[i][j++] = s[k++];
		tab[i][j] = '\0';
		i++;
	}
	tab[i] = 0;
	return (tab);
}
