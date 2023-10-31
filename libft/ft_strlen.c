/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:44:35 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/10/31 11:53:29 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

int	ft_strlen_dtab(char **s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}
