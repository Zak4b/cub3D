/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:12:02 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/16 17:44:14 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mouse_movement(t_vars *vars)
{
	int		x;
	int		y;
	int		delta_x;

	if (vars->inputs[ALT] == 1)
		return ;
	mlx_mouse_get_pos(vars->mlx->instance, vars->mlx->window, &x, &y);
	delta_x = x - W_WIDTH / 2;
	if (delta_x != 0)
	{
		vars->player->angle += delta_x * 0.002;
		x = W_WIDTH / 2;
		y = W_HEIGHT / 2;
		mlx_mouse_move(vars->mlx->instance, vars->mlx->window, x, y);
	}
}

void	print_on_minimap(t_vars *vars, int offx, int offy, int color)
{
	t_point	p;
	int		y;
	int		x;

	p.x = W_WIDTH - (MMAP_RAY - offx + 2) * MCELL_SIZE;
	p.y = W_HEIGHT - (MMAP_RAY - offy + 2) * MCELL_SIZE;
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

void	print_border(t_vars *vars)
{
	t_point	point;
	int		limit;

	limit = MMAP_RAY + 1;
	point.y = -limit - 1;
	while (++point.y <= limit)
	{
		point.x = -limit;
		while (point.x <= limit)
			print_on_minimap(vars, point.x++, point.y, 0xAAAAAA);
	}
}

void	print_minimap(t_vars *vars)
{
	t_point	point;
	t_point	player;
	t_point	test;

	player.x = (int) round(vars->player->pos.x) / CELL_SIZE;
	player.y = (int) round(vars->player->pos.y) / CELL_SIZE;
	print_border(vars);
	point.y = -MMAP_RAY - 1;
	while (++point.y <= MMAP_RAY)
	{
		point.x = -MMAP_RAY;
		while (point.x <= MMAP_RAY)
		{
			test.x = player.x + point.x;
			test.y = player.y + point.y;
			if (test.x == player.x && test.y == player.y)
				print_on_minimap(vars, point.x++, point.y, 0xFF0000);
			else if (test.x >= 0 && test.y >= 0
				&& test.x < vars->map->width && test.y < vars->map->height
				&& ft_strchr("0NSEW", vars->map->data[test.y][test.x]) != NULL)
				print_on_minimap(vars, point.x++, point.y, 0xFFFFFF);
			else
				print_on_minimap(vars, point.x++, point.y, 0x000000);
		}
	}
}
