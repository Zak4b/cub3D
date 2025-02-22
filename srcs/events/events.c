/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:56:06 by asene             #+#    #+#             */
/*   Updated: 2025/02/22 14:07:04 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>
#define CAMERA_ROTATION 0.03f
#define MOVE_HITBOX 0.2f

static int	is_wall(t_map *map, double x, double y)
{
	t_point	cell;

	cell.x = x / CELL_SIZE;
	cell.y = y / CELL_SIZE;
	if (cell.x < 0 || cell.x > map->width || cell.y < 0 || cell.y > map->height)
		return (0);
	return (map->data[cell.y][cell.x] == '1');
}

static int	is_near_wall(t_vars *vars, double x, double y)
{
	return (is_wall(vars->map, x + CELL_SIZE * MOVE_HITBOX, y)
		|| is_wall(vars->map, x - CELL_SIZE * MOVE_HITBOX, y)
		|| is_wall(vars->map, x, y + CELL_SIZE * MOVE_HITBOX)
		|| is_wall(vars->map, x, y - CELL_SIZE * MOVE_HITBOX));
}

void	move_player(t_vars *vars, t_dpoint mov)
{
	t_dpoint	dest;

	dest = (t_dpoint){vars->player->pos.x + mov.x, vars->player->pos.y + mov.y};
	if (! is_near_wall(vars, dest.x, vars->player->pos.y))
		vars->player->pos.x = dest.x;
	if (! is_near_wall(vars, vars->player->pos.x, dest.y))
		vars->player->pos.y = dest.y;
}

void	move(t_vars *vars)
{
	t_dpoint	p;
	double		ang;

	if (vars->inputs[ROTATE_L])
		vars->player->angle -= CAMERA_ROTATION;
	if (vars->inputs[ROTATE_R])
		vars->player->angle += CAMERA_ROTATION;
	p = (t_dpoint){0, 0};
	if (vars->inputs[MOVE_F])
		p.x++;
	if (vars->inputs[MOVE_B])
		p.x--;
	if (vars->inputs[MOVE_L])
		p.y--;
	if (vars->inputs[MOVE_R])
		p.y++;
	if (p.x == 0 && p.y == 0)
		return ;
	ang = atan2(p.y, p.x);
	p.x = cos(vars->player->angle + ang);
	p.y = sin(vars->player->angle + ang);
	if (vars->inputs[RUN])
		p = (t_dpoint){p.x * 2, p.y * 2};
	move_player(vars, p);
}
