/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 10:24:53 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/03 13:52:11 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	search_door(t_vars *vars)
{
	t_hit	hit;

	hit = cast_ray(vars->map, vars->player->pos, vars->player->angle, "D1O");
	if (hit.distance <= 1)
	{
		if (hit.collide_type == 'D')
		 	vars->map->data[hit.collide_cell.y][hit.collide_cell.x] = 'O';
		else if (hit.collide_type == 'O')
		 	vars->map->data[hit.collide_cell.y][hit.collide_cell.x] = 'D';
	}
	return (1);
}
