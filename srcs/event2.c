/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:02 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/13 00:52:19 by rsebasti         ###   ########.fr       */
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

void	print_on_minimap(t_vars *vars, t_point map_pos, int color)
{
	t_point	p;
	int		y;
	int		x;

	p.x = W_WIDTH - (vars->map->width - map_pos.x) * MCELL_SIZE;
	p.y = W_HEIGHT - (vars->map->height - map_pos.y) * MCELL_SIZE;
	y = 0;
	while (y < MCELL_SIZE)
	{
		x = 0;
		while (x < MCELL_SIZE)
		{
			put_pixel(vars->buffer, p.x + x, p.y + y, color);
			x++;
		}
		y++;
	}
}

void	print_minimap(t_vars *vars)
{
	t_point	point;

	point.y = 0;
	while (vars->map->data[point.y])
	{
		point.x = 0;
		while (vars->map->data[point.y][point.x])
		{
			if (vars->map->data[point.y][point.x] != '0')
				print_on_minimap(vars, point, 0x000000);
			else
				print_on_minimap(vars, point, 0xFFFFFF);
			point.x++;
		}
		point.y++;
	}

	point.x = (int) round(vars->player->pos.x) / CELL_SIZE;
	point.y = (int) round(vars->player->pos.y) / CELL_SIZE;
	print_on_minimap(vars, point, 0xFF0000);
}


