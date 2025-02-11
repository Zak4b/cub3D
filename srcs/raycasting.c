/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:19 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 10:34:29 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

int	in_map(t_map *map, int x, int y)
{
	return (x >= 0 && y >= 0 && x < map->width && y < map->height);
}

void	calc_steps(double angle, double *step_x, double *step_y)
{
	if (cos(angle) > 0)
		*step_x = CELL_SIZE;
	else
		*step_x = -CELL_SIZE;
	if (sin(angle) > 0)
		*step_y = CELL_SIZE;
	else
		*step_y = -CELL_SIZE;
}

int	check_collide(t_map *map, int x, int y)
{
	return (! in_map(map, x, y) || map->data[y][x] == '1');
}

t_dpoint	cast_ray(t_map *map, t_dpoint start, double angle)
{
	const double	tan_angle = tan(angle);
	double			step_x;
	double			step_y;
	t_point 		current_cell;

	calc_steps(angle, &step_x, &step_y);
	double nextVerticalX = floor(start.x / CELL_SIZE) * CELL_SIZE + (step_x > 0 ? CELL_SIZE : 0);
	double nextVerticalY = start.y + (nextVerticalX - start.x) * tan_angle;
	double nextHorizontalY = floor(start.y / CELL_SIZE) * CELL_SIZE + (step_y > 0 ? CELL_SIZE : 0);
	double nextHorizontalX = start.x + (nextHorizontalY - start.y) / tan_angle;

	while (1)
	{
		if (fabs(nextVerticalX - start.x) < fabs(nextHorizontalX - start.x))
		{
			current_cell.x = floor(nextVerticalX / CELL_SIZE) + (step_x < 0 ? -1 : 0);
			current_cell.y = floor(nextVerticalY / CELL_SIZE);
			if (check_collide(map, current_cell.x, current_cell.y))
				return ((t_dpoint){nextVerticalX, nextVerticalY});
			nextVerticalX += step_x;
			nextVerticalY += step_x * tan_angle;
		} else {
			current_cell.x = floor(nextHorizontalX / CELL_SIZE);
			current_cell.y = floor(nextHorizontalY / CELL_SIZE) + (step_y < 0 ? -1 : 0);
			if (check_collide(map, current_cell.x, current_cell.y))
				return ((t_dpoint){nextHorizontalX, nextHorizontalY});
			nextHorizontalX += step_y / tan_angle;
			nextHorizontalY += step_y;
		}
	}
	return ((t_dpoint){-1, -1});
}
