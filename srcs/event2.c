/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:02 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/12 14:52:53 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_movement(t_vars *vars)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(vars->mlx, vars->mlx_win, &x, &y);
	if (x < W_WIDTH / 2 && W_WIDTH / 2 - x > 200)
	{
		vars->player->angle -= 0.02;
		if (W_WIDTH / 2 - x > 2)
			x = x + 2;
		else
			x = W_WIDTH / 2;
		mlx_mouse_move(vars->mlx, vars->mlx_win, x, W_HEIGHT / 2);
	}
	if (x > W_WIDTH / 2 && x - W_WIDTH / 2 > 200)
	{
		vars->player->angle += 0.02;
		if (x - W_WIDTH / 2 > 2)
			x = x - 2;
		else
			x = W_WIDTH / 2;
		mlx_mouse_move(vars->mlx, vars->mlx_win, x, W_HEIGHT / 2);
	}

}
