/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:02:42 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/11/04 09:05:57 by hamzaelouar      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "../mlx_linux/mlx.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <stdbool.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <math.h>
# include <unistd.h>

typedef struct	s_play
{
	float	posx;
	float	posy;
}				t_play;

typedef struct	s_parse
{
	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*ceiling;
	char	*floor;
	char	**map;
	int		color_floor[3];
	int		color_ceiling[3];
}				t_parse;

typedef struct s_get_map
{
	char				*line;
	struct s_get_map	*next;
}				t_get_map;

typedef struct	s_data
{
	t_parse	*parse;
	t_play	*play;
}				t_data;

int		init_struct(t_data *data);

void	ft_free_all(t_data *data);

int		check_valid_file(t_parse *parse, int fd);

int		get_variable(t_parse *parse, char **split_line);

int		check_color(char **split_color, char *color, int i, int nb);

#endif