/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:02:18 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/10/31 11:15:34 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int argc, char **argv)
{
	t_play play;
	
	(void)argv;
	if (argc != 2)
		return (ft_putstr_fd("Error number args\n", 2), 1);
	play.px = 10;
	printf("valeur px : %f", play.px);
}