/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/13 00:10:43 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segment_size(double distance)
{
	return (((double)CELL_SIZE / (double)distance) * (double)W_WIDTH / (2 * tan((FOV * PI / 180) / 2)));
}

int	clamp_int(int n, int min, int max)
{
	if (n > max)
		n = max;
	if (n < min)
		n = min;
	return (n);
}

int	color_shadowing(int color, double distance)
{
	double			shadowing;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	shadowing = 1 - (distance / (CELL_SIZE)) * 0.15;
	red = clamp_int((int)((color >> 16 & 255) * shadowing), 0, 255);
	green = clamp_int((int)((color >> 8 & 255) * shadowing), 0, 255);
	blue = clamp_int((int)((color & 255) * shadowing), 0, 255);
	return (red << 16 | green << 8 | blue);
}

void	draw_walls(t_vars *vars)
{
	int			i;
	double		camera_x;
	double		ray_angle;
	t_dpoint	p;
	double		distance;
	int			size;
	int			color;

	i = 0;
	while (i < W_WIDTH)
	{
		camera_x = (2.0 * i / (W_WIDTH - 1)) - 1.0;
		ray_angle = vars->player->angle + atan(camera_x * tan((FOV * PI / 180) / 2));
		p = cast_ray(vars->map, vars->player->pos, ray_angle);
		distance = sqrt(pow(vars->player->pos.x - p.x, 2) + pow(vars->player->pos.y - p.y, 2));
		size = segment_size(distance * cos(ray_angle - vars->player->angle));
		color = color_shadowing(0x00FFA0, distance);
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
	print_minimap(vars);
	mlx_put_image_to_window(vars->mlx, vars->mlx_win, vars->buffer->img, 0, 0);
	mlx_do_sync(vars->mlx);
}
