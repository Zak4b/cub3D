/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:07 by asene             #+#    #+#             */
/*   Updated: 2025/03/10 10:50:48 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_game(t_vars *vars)
{
	int		win_width;
	int		win_height;
	t_point	player_cell;

	win_width = W_WIDTH;
	win_height = W_HEIGHT;
	vars->mlx = t_mlx_init(win_width, win_height, "cub3D");
	vars->buffer = new_image(vars->mlx, win_width, win_height);
	vars->player = malloc(sizeof(t_player));
	vars->player->angle = PI * 1.5;
	player_cell = find_player(vars->map->data);
	vars->player->pos = (t_dpoint){CELL_SIZE * (player_cell.x + .5), CELL_SIZE * (player_cell.y + .5)};
	vars->textures[NORTH] = load_img(vars->mlx, vars->map->style[NORTH]);
	vars->textures[SOUTH] = load_img(vars->mlx, vars->map->style[SOUTH]);
	vars->textures[EAST] = load_img(vars->mlx, vars->map->style[EAST]);
	vars->textures[WEST] = load_img(vars->mlx, vars->map->style[WEST]);
	vars->door_texture = load_img(vars->mlx, "./assets/brick_wall.xpm");
	vars->shadow = 1;
	ft_bzero(vars->inputs, sizeof(vars->inputs));
	mlx_hook(vars->mlx->window, 17, 0, mlx_loop_end, vars->mlx->instance);
	mlx_hook(vars->mlx->window, 2, 1L << 0, key_down_hook, vars);
	mlx_hook(vars->mlx->window, 3, 1L << 1, key_up_hook, vars);
	mlx_loop_hook(vars->mlx->instance, game_loop, vars);
	mlx_do_key_autorepeatoff(vars->mlx->instance);
	mlx_mouse_move(vars->mlx->instance, vars->mlx->window, W_WIDTH / 2, W_HEIGHT / 2);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map->data != NULL)
	{
		while (i < map->height)
			free(map->data[i++]);
		free(map->data);
	}
	i = 0;
	if (map->style != NULL)
	{
		while (map->style[i])
			free(map->style[i++]);
		free(map->style);
	}
	i = 0;
	if (map->discovered != NULL)
	{
		while (map->discovered[i])
			free(map->discovered[i++]);
		free(map->discovered);
	}
	free(map);
}

int	read_map(char *path, t_map *map)
{
	int	index;
	int	fd;

	map->style = NULL;
	map->discovered = NULL;
	map->data = NULL;
	index = ft_strlen(path) - 4;
	if (index < 0 || ft_strcmp(path + index, ".cub"))
		return (free(map), 0);
	fd = open(path, O_RDONLY);
	if (init_map(map, fd))
		return(free_map(map), 0);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (ft_fprintf(2, "USAGE"), 2);
	vars.map = malloc(sizeof(t_map));
	if (!read_map(argv[1], vars.map))
		return (1);
	init_game(&vars);
	mlx_loop(vars.mlx->instance);
	free(vars.player);
	free_map(vars.map);
	mlx_do_key_autorepeaton(vars.mlx->instance);
	t_mlx_kill(vars.mlx);
	exit(EXIT_SUCCESS);
}
