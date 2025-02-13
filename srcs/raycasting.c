/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:19 by asene             #+#    #+#             */
/*   Updated: 2025/02/13 10:50:52 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include "raycasting.h"

int	check_vertical_hit(t_map *map, t_cast_data *data)
{
	t_point	cell;

	cell = (t_point){floor(data->v_hit.x / CELL_SIZE),
		floor(data->v_hit.y / CELL_SIZE)};
	if (data->step.x < 0)
		cell.x--;
	if (check_collide(map, cell.x, cell.y))
		return (1);
	data->v_hit.x += data->step.x;
	data->v_hit.y += data->step.x * data->tan_angle;
	return (0);
}

int	check_horizontal_hit(t_map *map, t_cast_data *data)
{
	t_point	cell;

	cell = (t_point){floor(data->h_hit.x / CELL_SIZE),
		floor(data->h_hit.y / CELL_SIZE)};
	if (data->step.y < 0)
		cell.y--;
	if (check_collide(map, cell.x, cell.y))
		return (1);
	data->h_hit.x += data->step.y / data->tan_angle;
	data->h_hit.y += data->step.y;
	return (0);
}

t_dpoint	find_hit(t_map *map, t_cast_data data, int *direction)
{
	while (1)
	{
		if (fabs(data.v_hit.x - data.start.x)
			< fabs(data.h_hit.x - data.start.x))
		{
			if (check_vertical_hit(map, &data))
			{
				*direction = 0;
				return (data.v_hit);
			}
		}
		else
		{
			if (check_horizontal_hit(map, &data))
			{
				*direction = 1;
				return (data.h_hit);
			}
		}
	}
}

t_hit	cast_ray(t_map *map, t_dpoint start, double angle)
{
	t_hit		hit;
	int			direction;

	hit.pos = find_hit(map, calc_cast(start, angle), &direction);
	hit.distance = sqrt(pow(start.x - hit.pos.x, 2) + pow(start.y - hit.pos.y, 2));
	if (direction == 0)
	{
		hit.col_index = (int)hit.pos.y % CELL_SIZE;
		if (hit.pos.y > start.y)
			hit.side = NORTH;
		else
			hit.side = SOUTH;
	}
	else
	{
		hit.col_index = (int)hit.pos.x % CELL_SIZE;
		if (hit.pos.x > start.x)
			hit.side = EAST;
		else
			hit.side = WEST;
	}
	return (hit);
}
