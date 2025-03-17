/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:07 by asene             #+#    #+#             */
/*   Updated: 2025/03/17 12:00:47 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include "parsing.h"

void	load_textures(t_vars *vars)
{
	vars->textures[NORTH] = load_img(vars->mlx, vars->map->style[NORTH]);
	vars->textures[SOUTH] = load_img(vars->mlx, vars->map->style[SOUTH]);
	vars->textures[EAST] = load_img(vars->mlx, vars->map->style[EAST]);
	vars->textures[WEST] = load_img(vars->mlx, vars->map->style[WEST]);
	vars->torch = load_sprites(vars->mlx, "assets/torch/torch", 6);
	vars->torch_end = load_sprites(vars->mlx, "assets/torch/end", 6);
	vars->torch_start = load_sprites(vars->mlx, "assets/torch/start", 3);
	vars->door_texture = load_img(vars->mlx, "./assets/brick_wall.xpm");
}

void	init_game(t_vars *vars)
{
	int		win_width;
	int		win_height;
	t_point	player_cell;

	win_width = W_WIDTH;
	win_height = W_HEIGHT;
	vars->mlx = t_mlx_init(win_width, win_height, "cub3D");
	vars->buffer = new_image(vars->mlx, win_width, win_height);
	player_cell = vars->map->start_pos;
	vars->player.pos = (t_dpoint){CELL_SIZE * (player_cell.x + .5),
		CELL_SIZE * (player_cell.y + .5)};
	vars->player.angle = vars->map->start_dir;
	load_textures(vars);
	vars->shadow = 1;
	ft_bzero(vars->inputs, sizeof(vars->inputs));
	mlx_hook(vars->mlx->window, 17, 0, mlx_loop_end, vars->mlx->instance);
	mlx_hook(vars->mlx->window, 2, 1L << 0, key_down_hook, vars);
	mlx_hook(vars->mlx->window, 3, 1L << 1, key_up_hook, vars);
	mlx_loop_hook(vars->mlx->instance, game_loop, vars);
	mlx_do_key_autorepeatoff(vars->mlx->instance);
	mlx_mouse_move(vars->mlx->instance, vars->mlx->window,
		W_WIDTH / 2, W_HEIGHT / 2);
}

int	main(int argc, char *argv[])
{
	int		fd;
	t_vars	vars;

	if (argc != 2)
		return (ft_fprintf(2, "USAGE: %s <map.cub>\n", argv[0]), 2);
	fd = open_file(argv[1]);
	if (fd == -1)
		return (ft_puterror("no such file", ERROR));
	vars.map = read_file(fd);
	if (!vars.map)
		return (ft_puterror("incomplete map", ERROR));
	if (map_is_valid(vars.map))
		return (free_map(vars.map), EXIT_FAILURE);
	init_game(&vars);
	mlx_loop(vars.mlx->instance);
	free_map(vars.map);
	mlx_do_key_autorepeaton(vars.mlx->instance);
	t_mlx_kill(vars.mlx);
	free(vars.torch);
	exit(EXIT_SUCCESS);
}
