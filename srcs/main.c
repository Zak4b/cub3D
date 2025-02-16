/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:07 by asene             #+#    #+#             */
/*   Updated: 2025/02/16 21:18:57 by rsebasti         ###   ########.fr       */
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
	ft_bzero(vars->inputs, sizeof(vars->inputs));
	mlx_hook(vars->mlx->window, 17, 0, mlx_loop_end, vars->mlx->instance);
	mlx_hook(vars->mlx->window, 2, 1L << 0, key_down_hook, vars);
	mlx_hook(vars->mlx->window, 3, 1L << 1, key_up_hook, vars);
	mlx_loop_hook(vars->mlx->instance, game_loop, vars);
	mlx_do_key_autorepeatoff(vars->mlx->instance);
	mlx_mouse_hide(vars->mlx->instance, vars->mlx->window);
	mlx_mouse_move(vars->mlx->instance, vars->mlx->window, W_WIDTH / 2, W_HEIGHT / 2);
}

int	read_map(char *path, t_map *map)
{
	int	index;
	int	fd;

	index = ft_strlen(path) - 4;
	if (index < 0 || ft_strcmp(path + index, ".cub"))
		return (0);
	fd = open(path, O_RDONLY);
	return (!init_map(map, fd));
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	while (i < map->height)
	{
		free(map->data[i]);
		i++;
	}
	free(map->data);
	i = 0;
	while (map->style[i])
	{
		free(map->style[i]);
		i++;
	}
	free (map->style);
	free(map);
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
