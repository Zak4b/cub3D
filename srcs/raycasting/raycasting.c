/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:19 by asene             #+#    #+#             */
/*   Updated: 2025/03/03 11:48:23 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include "raycasting.h"
#define VERTICAL 1
#define HORIZONTAL 2

int	check_vertical_hit(t_map *map, t_cast_data *data, t_point *collide_cell)
{
	t_point	cell;

	cell.x = floor(data->v_hit.x / CELL_SIZE);
	cell.y = floor(data->v_hit.y / CELL_SIZE);
	if (data->step.x < 0)
		cell.x--;
	if (check_collide(map, cell.x, cell.y))
	{
		if (collide_cell)
			*collide_cell = cell;
		return (1);
	}
	data->v_hit.x += data->step.x;
	data->v_hit.y += data->step.x * data->tan_angle;
	return (0);
}

int	check_horizontal_hit(t_map *map, t_cast_data *data, t_point *collide_cell)
{
	t_point	cell;

	cell.x = floor(data->h_hit.x / CELL_SIZE);
	cell.y = floor(data->h_hit.y / CELL_SIZE);
	if (data->step.y < 0)
		cell.y--;
	if (check_collide(map, cell.x, cell.y))
	{
		if (collide_cell)
			*collide_cell = cell;
		return (1);
	}
	data->h_hit.x += data->step.y / data->tan_angle;
	data->h_hit.y += data->step.y;
	return (0);
}

void find_hit(t_map *map, t_cast_data data, int *axis, t_hit *hit)
{
	t_point	collide_cell;

	while (1)
	{
		if (fabs(data.v_hit.x - data.start.x)
			< fabs(data.h_hit.x - data.start.x))
		{
			if (check_vertical_hit(map, &data, &collide_cell))
			{
				*axis = VERTICAL;
				hit->collide_type = map->data[collide_cell.y][collide_cell.x];
				return (hit->pos = data.v_hit, (void)0);
			}
		}
		else
		{
			if (check_horizontal_hit(map, &data, &collide_cell))
			{
				*axis = HORIZONTAL;
				hit->collide_type = map->data[collide_cell.y][collide_cell.x];
				return (hit->pos = data.h_hit, (void)0);
			}
		}
	}
}

void	fill_hit_struct(t_hit *hit, t_dpoint start, int axis)
{
	if (axis == VERTICAL)
	{
		hit->col_index = (int)hit->pos.y % CELL_SIZE;
		if (hit->pos.x <= start.x)
			hit->side = D_WEST;
		else
			hit->side = D_EAST;
	}
	else
	{
		hit->col_index = (int)hit->pos.x % CELL_SIZE;
		if (hit->pos.y <= start.y)
			hit->side = D_NORTH;
		else
			hit->side = D_SOUTH;
	}
	if (hit->side == D_SOUTH || hit->side == D_WEST)
		hit->col_index = CELL_SIZE - 1 - hit->col_index;
}

t_hit	cast_ray(t_map *map, t_dpoint start, double angle)
{
	t_hit	hit;
	int		axis;

	find_hit(map, calc_cast(start, angle), &axis, &hit);
	hit.distance = sqrt(pow(start.x - hit.pos.x, 2) + pow(start.y - hit.pos.y, 2));
	hit.distance /= (double)CELL_SIZE;
	fill_hit_struct(&hit, start, axis);
	return (hit);
}
