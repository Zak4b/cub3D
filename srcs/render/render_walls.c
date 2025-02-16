/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/02/16 09:52:05 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

double	segment_size(double distance)
{
	return ((double)W_WIDTH / (2 * TAN_HALF_FOV) / distance);
}

int	get_pixel_scale(t_img *img, int x, int y, int size)
{
	return (get_pixel(img, x * img->width / CELL_SIZE, y * img->height / size));
}

void	draw_wall_segment(t_vars *vars, int ray_index, t_hit hit, int size)
{
	int	j;
	int	color;

	j = 0;
	while (j < size)
	{
		color = get_pixel_scale(vars->textures[hit.side], hit.col_index, j, size);
		color =  color_shadowing(color, hit.distance);
		put_pixel(vars->buffer, ray_index, j + (W_HEIGHT - size) / 2, color);
		j++;
	}
}

void	draw_walls(t_vars *vars)
{
	int			i;
	double		camera_x;
	double		ray_angle;
	t_hit		hit;
	int			size;

	i = 0;
	while (i < W_WIDTH)
	{
		camera_x = (2.0 * i / (W_WIDTH - 1)) - 1.0;
		ray_angle = vars->player->angle + atan(camera_x * TAN_HALF_FOV);
		hit = cast_ray(vars->map, vars->player->pos, ray_angle);
		size = segment_size(hit.distance * cos(ray_angle - vars->player->angle));
		draw_wall_segment(vars, i, hit, size);
		i++;
	}
}
