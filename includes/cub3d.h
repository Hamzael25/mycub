/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hamzaelouardi <hamzaelouardi@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 08:02:42 by hel-ouar          #+#    #+#             */
/*   Updated: 2023/12/02 21:05:32 by hamzaelouar      ###   ########.fr       */
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

# define PI 3.14159265
# define H_WHITE	0xffffff
# define H_BLACK 0x000000
# define H_PINK 0xffc0cb
# define H_GREY 0x808080
# define TILE_SIZE 32
# define FOV_ANGLE 60.0
# define DR 0.0174533
# define WINHEIGHT 1080
# define WINWIDTH 1920
# define ESC 65307
# define W 119
# define A 97
# define S 115
# define D 100
# define LEFT 65361
# define RIGHT 65363

typedef struct s_play
{
	float	posx;
	float	posy;
	float	px;
	float	py;
	float	pa;
	bool	key_states[65365];
}				t_play;

typedef struct s_parse
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*ceiling;
	char			*floor;
	int				biger;
	char			**map;
	int				hmap;
	int				wmap;
	int				color_floor[3];
	int				color_ceiling[3];
	unsigned int	color_floor_hexa;
	unsigned int	color_ceiling_hexa;
	char			orientation;
}				t_parse;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}						t_win;

typedef struct s_sprite
{
	void	*img;
	char	*addr;
	int		width;
	int		height;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_sprite;

typedef struct s_stage
{
	float	dis_v;
	float	dis_h;
	float	dist;
	float	rx;
	float	ry;
	float	vx;
	float	vy;
	float	hx;
	float	hy;
	int		r;
	float	ra;
	float	h_redded;
	int		line_h;
	float	ca;
	float	ty_step;
	float	ty_off;
	int		line_off;
	float	ty;
	float	tx;
	int		dof;
	int		mx;
	int		my;
	float	xo;
	float	yo;

}				t_stage;

typedef struct s_data
{
	t_parse		*parse;
	t_play		*play;
	t_win		*win;
	t_sprite	*no_text;
	t_sprite	*so_text;
	t_sprite	*ea_text;
	t_sprite	*we_text;
	t_stage		*stage;
}				t_data;

int			init_struct(t_data *data);

int			init_struct_data(t_data *data);

void		ft_free_all(t_data *data, int mod);

void		free_win(t_data *data, int mod);

int			parsing(char *map, t_data *data);

int			parsing_map(t_parse *parse);

int			check_valid_file(t_parse *parse, int fd);

int			get_variable(t_parse *parse, char **split_line);

int			check_color(char **split_color, char *color, int i, int nb);

int			check_char(char *str, int *p, t_parse *parse);

void		replace_space(char *line);

int			only_wall(char *str);

int			check_wall(t_parse *parse, int i, int j, int save);

int			check_player(char **map);

int			is_player(char p);

int			check_map(char **map);

int			nb_of_space(char **str, int *i);

int			check_path(t_data *data);

int			check_open_file(t_data *data, char *file, int flg);

int			check_file(char *map, char *ext);

void		set_color_c_f(t_data *data);

int			get_sprite(char **path, char **split_line);

int			set_sprite(t_parse *parse, char **split_line);

int			set_color(t_parse *parse, char **split_line);

int			get_color(t_parse *parse, char *color, int flg);

void		free_struct(t_data *data);

void		free_parse(t_parse *parse);

int			get_position(int flg, char **map);

void		get_dimention(t_parse *parse);

int			start_game(t_win *win, t_data *data);

int			init_sprite(t_data *d, t_parse *parse);

void		init_sprites(t_data *d);

int			close_win(t_data *data);

int			key_press_hook(int keycode, t_data *data);

int			key_release_hook(int keycode, t_data *data);

int			random_next_frame(t_data *data);

void		check_collision(t_data *data, float newX, float newY, \
			float c_margin);

bool		is_collision(t_data *data, float newx, float newy);

void		move(t_data *data);

void		check_key_and_set_new_position(t_data *data, float moveSpeed, \
			float *newX, float *newY);

void		check_key_and_set_new_angle(t_data *data, float rotateSpeed);

void		check_esc_key(t_data *data);

void		ray_cast(t_data *data, t_stage *stage);

void		check_horizontal_line(t_stage *s, t_data *d);

void		looking_horizontal(t_stage *stage, t_data *d);

void		init_horizontal(t_stage *s, t_data *d);

float		dist(float ax, float ay, float bx, float by);

void		check_vertical_line(t_stage *s, t_data *d);

void		init_vertical(t_stage *s, t_data *d);

void		looking_vertical(t_stage *stage, t_data *data);

void		choose_line(t_stage *stage);

void		draw_stage(t_data *data, t_stage *stage, int r, float ra);

void		draw_sprites(t_data *data, int r, float ra);

void		define_which_sprite(t_data *data, t_sprite **sprite, float ra);

void		draw_s_and_n_sprite(t_data *data, float ra, t_sprite **sprite);

void		draw_e_and_w_sprite(t_data *data, float ra, t_sprite **sprite);

void		put_sprite(t_sprite *sprite, t_data *data, int r);

void		put_pixel(t_win *draw, int x, int y, int color);

void		draw_map_view(t_data *data, int i, int j, int x);

void		set_initial_player_position(t_data *data, int *startx, int *starty);

void		draw_tile(t_data *data, char map_val, int x, int y);

void		update_player_spawn(t_data *data);

void		render_wall_tile(t_data *data, int color, int x, int y);

#endif