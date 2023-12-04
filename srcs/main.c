/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:02:18 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/12/04 17:43:39 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc == 2)
	{
		if (!init_struct(&data))
			return (ft_free_all(&data, 0), 1);
		if (parsing(argv[1], &data) || !init_struct_data(&data) \
			|| start_game(data.win, &data))
			return (ft_free_all(&data, 1), 1);
		return (ft_free_all(&data, 0), 0);
	}
	return (ft_putstr_fd("Error number args\n", 2), 1);
}
