/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:24:53 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/25 10:52:15 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static int	is_door(t_map *map, double x, double y)
{
	t_point	cell;

	cell.x = x / CELL_SIZE;
	cell.y = y / CELL_SIZE;
	if (cell.x < 0 || cell.x > map->width || cell.y < 0 || cell.y > map->height)
		return (0);
	if (map->data[cell.y][cell.x] == 'O')
		map->data[cell.y][cell.x] = 'D';
	else if (map->data[cell.y][cell.x] == 'D')
		map->data[cell.y][cell.x] = 'O';
	return (1);
}

int	search_door(t_vars *vars)
{
	double	x;
	double	y;

	x = vars->player->pos.x;
	y = vars->player->pos.y;
	is_door(vars->map, x + CELL_SIZE * DOOR_HITBOX, y);
	is_door(vars->map, x - CELL_SIZE * DOOR_HITBOX, y);
	is_door(vars->map, x, y + CELL_SIZE * DOOR_HITBOX);
	is_door(vars->map, x, y - CELL_SIZE * DOOR_HITBOX);
	return (1);
}

