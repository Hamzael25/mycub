/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 07:34:41 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 08:33:19 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
