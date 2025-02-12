/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:02 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/12 15:51:23 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_movement(t_vars *vars)
{
	int		x;
	int		y;
	int		delta_x;

	mlx_mouse_get_pos(vars->mlx, vars->mlx_win, &x, &y);
	delta_x = x - W_WIDTH / 2;
	if (delta_x != 0)
	{
		vars->player->angle += delta_x * 0.002;
		mlx_mouse_move(vars->mlx, vars->mlx_win, W_WIDTH / 2, W_HEIGHT / 2);
	}
}
