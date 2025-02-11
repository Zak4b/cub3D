/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 14:50:11 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segmentSize(double distance)
{
	return ((double)CELL_SIZE / (double)distance) * (double)W_WIDTH / (2 * tan(1.309 / 2));
}

double	correctedDistance(t_vars *vars, double distance, double rayAngle)
{
	return (distance * cos(rayAngle - vars->player->angle));
}
int	clamp_int(int n, int min, int max)
{
	if (n > max)
		n = max;
	if (n < min)
		n = min;
	return (n);
}

void draw_walls(t_vars *vars)
{
	int	i;
	const int rayCount = W_WIDTH;
	double ang = (75 * PI / 180) / (rayCount - 1);
	double ray_angle;
	i = 0;
	while (i < rayCount)
	{
		ray_angle = vars->player->angle - (75 * PI / 180) / 2 + ang * i;
		t_dpoint p = cast_ray(vars->map, vars->player->pos, ray_angle);
		double	distance = sqrt(pow(vars->player->pos.x - p.x, 2) + pow(vars->player->pos.y - p.y, 2));;
		int size = segmentSize(correctedDistance(vars, distance, ray_angle));
		double shadowing = 1 - (distance / (CELL_SIZE)) * 0.15;
		int a = clamp_int((int)(0x0F * shadowing), 0 , 255)  << 16 | clamp_int((int)(0xFF * shadowing), 0, 255)  << 8 | clamp_int((int)(0xFF * shadowing), 0, 255);
		draw_vline(vars->buffer, (t_point){i, (W_HEIGHT - size) / 2}, size, a);
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