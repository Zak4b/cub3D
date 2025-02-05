/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2025/02/05 15:59:28 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	key_down_hook(int k, t_vars *vars)
{
	if (k == KEY_ESC)
		close_window(vars);
	return (0);
}

int	key_up_hook(int k, t_vars *vars)
{
	(void)k;
	(void)vars;
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	exit(EXIT_SUCCESS);
	return (0);
}

int	game_loop(t_vars *vars)
{
	(void)vars;
	sleep(1);
	//mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer, 0, 0);
	//mlx_do_sync(vars->mlx);
	return (1);
}
