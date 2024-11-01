/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:34:41 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 09:14:34 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_countword(const char *s)
{
	int	i;
	int	j;

	j = 0;
	i = 0;
	while (s[i])
	{
		if ((s[i] == ',' || s[i] == '\n' || s[i] == '\0') == 0
			&& (s[i + 1] == ',' || s[i + 1] == '\n' || s[i + 1] == '\0') == 1)
			j++;
		i++;
	}
	return (j + 1);
}

static int	ft_sizeword(const char *s, int index)
{
	int	count;

	count = 0;
	while (s[index] && s[index] != ',' && s[index] != '\n')
	{
		index++;
		count++;
	}
	return (count + 1);
}

char	**ft_split4(char const *s)
{
	char	**tab;
	int		i;
	int		j;
	int		k;

	i = 0;
	k = 0;
	j = 0;
	tab = (char **)malloc(sizeof(char *) * ft_countword(s));
	if (!tab || !s)
		return (NULL);
	while (s[k] && i < ft_countword(s) - 1)
	{
		while (s[k] == ',' || s[k] == '\n')
			k++;
		tab[i] = (char *)malloc(sizeof(char) * ft_sizeword(s, k));
		if (!tab[i])
			return (NULL);
		j = 0;
		while (s[k] && s[k] != ',' && s[k] != '\n')
			tab[i][j++] = s[k++];
		tab[i++][j] = '\0';
	}
	tab[i] = NULL;
	return (tab);
}
