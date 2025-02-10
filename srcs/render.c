/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/10 16:24:09 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segmentSize(int distance)
{
	return ((double)CELL_SIZE / (double)distance) * (double)W_WIDTH / (2 * tan(1.309 / 2));
}

int	correctedDistance(t_vars *vars, t_dpoint point, double rayAngle)
{
	double distance;

	distance = sqrt(pow(vars->player->pos.x - point.x, 2) + pow(vars->player->pos.y - point.y, 2));
	return (distance * cos(rayAngle - vars->player->angle));
}

void draw_walls(t_vars *vars)
{
	int	i;
	const int rayCount = W_WIDTH;
	double ang = (75 * 3.14 / 180) / (rayCount - 1);
	double ray_angle;
	i = 0;
	while (i < rayCount)
	{
		ray_angle = vars->player->angle - (75 * 3.14 / 180) / 2 + ang * i;
		t_dpoint p = cast_ray(vars->map, vars->player->pos, ray_angle);
		int	distance = correctedDistance(vars, p, ray_angle);
		int size = segmentSize(distance);
		draw_vline(vars->buffer, (t_point){i, (W_HEIGHT - size) / 2}, size, 0xFFFFF);
		i++;
	}
}

void	draw_background(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < W_WIDTH)
	{
		draw_vline(vars->buffer, (t_point){i, 0}, W_HEIGHT /2, 0x1b237a);
		draw_vline(vars->buffer, (t_point){i, W_HEIGHT /2}, W_HEIGHT /2, 0x555555);
		i++;
	}
}

void	render(t_vars *vars)
{
	draw_background(vars);
	draw_walls(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer->img, 0, 0);
	mlx_do_sync(vars->mlx);
}