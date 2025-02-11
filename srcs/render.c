/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 23:53:14 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segment_size(double distance)
{
	return (((double)CELL_SIZE / (double)distance) * (double)W_WIDTH / (2 * tan(1.309 / 2)));
}

double	corrected_distance(t_vars *vars, double distance, double rayAngle)
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

void	draw_walls(t_vars *vars)
{
	int			i;
	double		camera_x;
	double		ray_angle;
	t_dpoint	p;
	double		distance;
	int			size;
	double		shadowing;
	int			color;

	i = 0;
	while (i < W_WIDTH)
	{
		camera_x = (2.0 * i / (W_WIDTH - 1)) - 1.0;
		ray_angle = vars->player->angle + atan(camera_x * tan((75 * PI / 180) / 2));
		p = cast_ray(vars->map, vars->player->pos, ray_angle);
		distance = sqrt(pow(vars->player->pos.x - p.x, 2) + pow(vars->player->pos.y - p.y, 2));
		size = segment_size(corrected_distance(vars, distance, ray_angle));
		shadowing = 1 - (distance / (CELL_SIZE)) * 0.15;
		color = clamp_int((int)(0x00 * shadowing), 0, 255) << 16 | clamp_int((int)(0xFF * shadowing), 0, 255) << 8 | clamp_int((int)(0xA0 * shadowing), 0, 255);
		draw_vline(vars->buffer, (t_point){i, (W_HEIGHT - size) / 2}, size, color);
		i++;
	}
}

void	draw_background(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < W_WIDTH)
	{
		draw_vline(vars->buffer, (t_point){i, 0}, W_HEIGHT / 2, 0x1b237a);
		draw_vline(vars->buffer, (t_point){i, W_HEIGHT / 2}, W_HEIGHT / 2, 0x555555);
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
