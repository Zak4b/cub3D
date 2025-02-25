/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:24:53 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/25 11:22:37 by rsebasti         ###   ########.fr       */
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

int	get_color(char	**map, t_point point, t_point player)
{
	if (point.x == player.x && point.y == player.y)
		return (0xFF0000);
	if (map[point.y][point.x] == '2')
		return (0xFFFFFF);
	if (map[point.y][point.x] == '3')
		return (0xCCCCCC);
	if (map[point.y][point.x] == '4')
		return (0xDDDDDD);
	return (0x000000);
}

