/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:19 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 16:21:03 by asene            ###   ########.fr       */
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

t_dpoint	find_hit(t_map *map, t_cast_data data)
{
	while (1)
	{
		if (fabs(data.v_hit.x - data.start.x)
			< fabs(data.h_hit.x - data.start.x))
		{
			if (check_vertical_hit(map, &data))
				return (data.v_hit);
		}
		else
		{
			if (check_horizontal_hit(map, &data))
				return (data.h_hit);
		}
	}
}

t_dpoint	cast_ray(t_map *map, t_dpoint start, double angle)
{
	t_dpoint		hit;

	hit = find_hit(map, calc_cast(start, angle));
	return (hit);
}
