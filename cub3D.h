/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:53 by asene             #+#    #+#             */
/*   Updated: 2025/02/12 13:00:32 by asene            ###   ########.fr       */
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

# define CELL_SIZE 64
# define FOV 75
# define W_WIDTH 1920
# define W_HEIGHT 1080
# ifndef PI
#  define PI 3.14159265359
# endif

typedef struct s_map
{
	int		width;
	int		height;
	char	**data;
	char	**style;
}	t_map;

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

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

typedef enum e_direction
{
	D_LEFT = 0,
	D_UP = 1,
	D_RIGHT = 2,
	D_DOWN = 3
}	t_direction;

typedef struct s_player
{
	t_dpoint	pos;
	float		angle;
}	t_player;

typedef struct s_vars
{
	void		*mlx;
	void		*mlx_win;
	t_player	*player;
	t_map		*map;
	t_img		*buffer;
	int			inputs[20];
}	t_vars;

void		put_pixel(t_img *img, int x, int y, int color);
void		put_image(t_img *dest, t_img *img, int x0, int y0);
void		draw_vline(t_img *dest, t_point p, int h, int color);

void		free_image(t_vars *vars, t_img *img);
void		clear_array_img(t_vars *vars, t_img **imgs);
t_img		*new_image(void *mlx, int width, int height);
t_img		*load_img(t_vars *vars, char *path);
t_img		**load_sprites(t_vars *vars, char *path, unsigned int count);

int			key_down_hook(int k, t_vars *vars);
int			key_up_hook(int k, t_vars *vars);
int			close_window(t_vars *vars);
int			game_loop(t_vars *vars);

t_dpoint	cast_ray(t_map *map, t_dpoint start, double angle);

void		render(t_vars *vars);

int			ft_strchrs(char *str, char *chrs);
int			init_map(t_map *map, int fd);
int			add_style(t_map *map, char *line);
char		*line_dup(const char *src, int len);
t_point		find_player(char **map);
int			checker(char **map, t_map *tmap);
int			invalid_style(char *style);
int			ft_puterror(char *str, int type);

#endif