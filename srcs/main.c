/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 11:47:07 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 12:21:21 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	init_game(t_vars *vars)
{
	int	win_width;
	int	win_height;

	win_width = 960;
	win_height = 480;
	vars->mlx = mlx_init();
	vars->mlx_win = mlx_new_window(vars->mlx, win_width, win_height, "cub3D");
	vars->buffer = new_image(vars->mlx, win_width, win_height);
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
	init_map(map, fd);
	return (1);
}

int	main(int argc, char *argv[])
{
	t_map	map;

	if (argc != 2)
		return (ft_fprintf(2, "USAGE"), 2);
	read_map(argv[1], &map);
}
