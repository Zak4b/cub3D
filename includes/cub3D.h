/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:53 by asene             #+#    #+#             */
/*   Updated: 2025/02/15 16:51:12 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdlib.h>
# include <libft.h>
# include <math.h>
# include <mlx.h>
# include <fcntl.h>
# include <unistd.h>
# include <limits.h>
# include "mlx_utils.h"

# define CELL_SIZE 64
# define SHADOWING 0.15
# define MCELL_SIZE 10
# define FOV 75
# define TAN_HALF_FOV tan((FOV * PI / 180) / 2)
# define W_WIDTH 1080
# define W_HEIGHT 540
# ifndef PI
#  define PI 3.14159265359
# endif

typedef enum e_error_type
{
	ERROR,
	WARNING,
}	t_error_type;

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
	char	*style[6];
}	t_map;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_dpoint
{
	double	x;
	double	y;
}	t_dpoint;

typedef enum e_keycode
{
	KEY_SPACE = 32,
	KEY_ESC = 65307,
	KEY_W = 119,
	KEY_A = 97,
	KEY_S = 115,
	KEY_D = 100,
	KEY_A_LEFT = 65361,
	KEY_A_RIGHT = 65363,
	KEY_SHIFT = 65505,
}	t_keycode;

typedef enum e_input
{
	MOVE_F,
	MOVE_B,
	MOVE_L,
	MOVE_R,
	ROTATE_L,
	ROTATE_R,
	RUN,
}	t_input;

typedef struct s_keymap
{
	int		key;
	t_input	input;
}	t_keymap;

typedef enum e_direction
{
	NORTH = 0,
	EAST = 1,
	SOUTH = 2,
	WEST = 3
}	t_direction;

typedef struct s_hit
{
	t_dpoint	pos;
	double		distance;
	t_direction	side;
	int			col_index;
}	t_hit;


typedef struct s_player
{
	t_dpoint	pos;
	float		angle;
}	t_player;

typedef struct s_vars
{
	t_mlx		*mlx;
	t_player	*player;
	t_map		*map;
	t_img		*buffer;
	int			inputs[20];
	t_img		*wall;
	t_img		*grass;
}	t_vars;

int			key_down_hook(int k, t_vars *vars);
int			key_up_hook(int k, t_vars *vars);
int			game_loop(t_vars *vars);

t_hit		cast_ray(t_map *map, t_dpoint start, double angle);

void		move(t_vars *vars);

void		draw_vline(t_img *dest, t_point p, int h, int color);
void		draw_hline(t_img *dest, t_point p, int l, int color);
void		draw_background(t_vars *vars);
void		draw_walls(t_vars *vars);

int			init_map(t_map *map, int fd);
int			add_style(t_map *map, char *line);
int			checker(char **map, t_map *tmap);
int			invalid_style(char *style);
void		mouse_movement(t_vars *vars);
void		print_minimap(t_vars *vars);

int			ft_strchrs(char *str, char *chrs);
int			clamp_int(int n, int min, int max);
int			ft_puterror(char *str, t_error_type type);
char		*line_dup(const char *src, int len);
t_point		find_player(char **map);

#endif