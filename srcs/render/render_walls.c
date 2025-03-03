/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/05 16:10:42 by asene             #+#    #+#             */
/*   Updated: 2025/03/03 11:55:57 by asene            ###   ########.fr       */
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
	int		i;
	int		j;
	int		color;
	t_img	*texture;

	if (hit.collide_type == 'D')
		texture = vars->door_texture;
	else
		texture = vars->textures[hit.side];
	if (size <= W_HEIGHT)
	{
		i = 0;
		j = size;
	}
	else
	{
		i = (size - W_HEIGHT) / 2;
		j = W_HEIGHT + i;
	}
	while (i < j)
	{
		color = get_pixel_scale(texture, hit.col_index, i, size);
		if (vars->shadow)
			color =  color_shadowing(color, hit.distance);
		put_pixel(vars->buffer, ray_index, i + (W_HEIGHT - size) / 2, color);
		i++;
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
