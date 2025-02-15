/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/15 20:12:14 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segment_size(double distance)
{
	return ((CELL_SIZE / distance) * (double)W_WIDTH / (2 * TAN_HALF_FOV));
}

int	color_shadowing(int color, double distance)
{
	double			shadowing;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	shadowing = 1 - (distance / (CELL_SIZE)) * SHADOWING;
	red = clamp_int((int)((color >> 16 & 255) * shadowing), 0, 255);
	green = clamp_int((int)((color >> 8 & 255) * shadowing), 0, 255);
	blue = clamp_int((int)((color & 255) * shadowing), 0, 255);
	return (red << 16 | green << 8 | blue);
}

void	draw_walls(t_vars *vars)
{
	int			i;
	int			j;
	double		camera_x;
	double		ray_angle;
	t_hit		hit;
	int			size;
	int			color;

	i = 0;
	while (i < W_WIDTH)
	{
		camera_x = (2.0 * i / (W_WIDTH - 1)) - 1.0;
		ray_angle = vars->player->angle + atan(camera_x * TAN_HALF_FOV);
		hit = cast_ray(vars->map, vars->player->pos, ray_angle);
		size = segment_size(hit.distance * cos(ray_angle - vars->player->angle));
		j = 0;
		while (j < size)
		{
			color = get_pixel(vars->wall, hit.col_index * vars->wall->width / CELL_SIZE, j * vars->wall->height / size);
			put_pixel(vars->buffer, i, j + (W_HEIGHT - size) / 2, color_shadowing(color, hit.distance));
			j++;
		}
		i++;
	}
}

void	draw_background(t_vars *vars)
{
	int	i;
	int	color;

	i = 0;
	while (i < W_HEIGHT / 2)
		draw_hline(vars->buffer, (t_point){0, i++}, W_WIDTH, 0x82733f);
	while (i < W_HEIGHT)
	{
		color = color_shadowing(0x736a3e,
				CELL_SIZE / SHADOWING - (i - W_HEIGHT / 2));
		draw_hline(vars->buffer, (t_point){0, i}, W_WIDTH, color);
		i++;
	}
}
