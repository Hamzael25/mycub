/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-ouar <hel-ouar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:02:18 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 09:31:48 by hel-ouar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3D.h"

int main(int argc, char **argv)
{
	t_data data;
	
	(void)argv;
	if (argc != 2)
		return (ft_putstr_fd("Error number args\n", 2), 1);
	if (!init_struct(&data))
		return (ft_free_all(&data), 1);
	if (parsing(argv[1], &data))
	{
		printf("test");
		// return (ft_free_all(&data), 1);
	}
}
