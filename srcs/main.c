/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:07 by asene             #+#    #+#             */
/*   Updated: 2025/02/12 14:50:34 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_game(t_vars *vars)
{
	int	win_width;
	int	win_height;

	win_width = W_WIDTH;
	win_height = W_HEIGHT;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, win_width, win_height, "cub3D");
	vars->buffer = new_image(vars->mlx, win_width, win_height);
	vars->player = malloc(sizeof(t_player));
	vars->player->angle = PI * 1.5;
	vars->player->pos = (t_dpoint){64 * 7, 64 * 7};
	ft_bzero(vars->inputs, sizeof(vars->inputs));
	mlx_hook(vars->mlx_win, 17, 0, close_window, vars);
	mlx_hook(vars->mlx_win, 2, 1L << 0, key_down_hook, vars);
	mlx_hook(vars->mlx_win, 3, 1L << 1, key_up_hook, vars);
	mlx_loop_hook(vars->mlx, game_loop, vars);
	mlx_do_key_autorepeatoff(vars->mlx);
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

int	main(int argc, char *argv[])
{
	t_vars	vars;

	if (argc != 2)
		return (ft_fprintf(2, "USAGE"), 2);
	vars.map = malloc(sizeof(t_map));
	if (!read_map(argv[1], vars.map))
		return (1);
	init_game(&vars);
	mlx_mouse_move(vars.mlx, vars.mlx_win, W_WIDTH / 2, W_HEIGHT / 2);
	mlx_loop(vars.mlx);
}
