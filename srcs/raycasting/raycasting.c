/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:24:19 by asene             #+#    #+#             */
/*   Updated: 2025/03/03 13:50:41 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#include "raycasting.h"

int	check_vertical_hit(t_map *map , char *collide_set, t_cast_data *data, t_point *collide_cell)
{
	t_point	cell;

	cell.x = floor(data->v_hit.x / CELL_SIZE);
	cell.y = floor(data->v_hit.y / CELL_SIZE);
	if (data->step.x < 0)
		cell.x--;
	if (check_collide(map, collide_set, cell.x, cell.y))
	{
		if (collide_cell)
			*collide_cell = cell;
		return (1);
	}
	data->v_hit.x += data->step.x;
	data->v_hit.y += data->step.x * data->tan_angle;
	return (0);
}

int	check_horizontal_hit(t_map *map , char *collide_set, t_cast_data *data, t_point *collide_cell)
{
	t_point	cell;

	cell.x = floor(data->h_hit.x / CELL_SIZE);
	cell.y = floor(data->h_hit.y / CELL_SIZE);
	if (data->step.y < 0)
		cell.y--;
	if (check_collide(map, collide_set, cell.x, cell.y))
	{
		if (collide_cell)
			*collide_cell = cell;
		return (1);
	}
	data->h_hit.x += data->step.y / data->tan_angle;
	data->h_hit.y += data->step.y;
	return (0);
}

void find_hit(t_map *map, char *collide_set, t_cast_data data, t_hit *hit)
{
	t_point	collide_cell;

	while (1)
	{
		if (fabs(data.v_hit.x - data.start.x)
			< fabs(data.h_hit.x - data.start.x))
		{
			if (check_vertical_hit(map, collide_set, &data, &collide_cell))
			{
				hit->axis = VERTICAL;
				hit->collide_cell = collide_cell;
				return (hit->pos = data.v_hit, (void)0);
			}
		}
		else
		{
			if (check_horizontal_hit(map, collide_set, &data, &collide_cell))
			{
				hit->axis = HORIZONTAL;
				hit->collide_cell = collide_cell;
				return (hit->pos = data.h_hit, (void)0);
			}
		}
	}
}

void	fill_hit_struct(t_hit *hit, t_dpoint start)
{
	if (hit->axis == VERTICAL)
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

t_hit	cast_ray(t_map *map, t_dpoint start, double angle, char *collide_set)
{
	t_hit	hit;

	find_hit(map, collide_set, calc_cast(start, angle), &hit);
	hit.distance = sqrt(pow(start.x - hit.pos.x, 2) + pow(start.y - hit.pos.y, 2));
	hit.distance /= (double)CELL_SIZE;
	fill_hit_struct(&hit, start);
	hit.collide_type = map->data[hit.collide_cell.y][hit.collide_cell.x];
	return (hit);
}
