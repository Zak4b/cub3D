/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 01:56:06 by asene             #+#    #+#             */
/*   Updated: 2025/02/17 13:26:38 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	move_player(t_vars *vars, t_dpoint mov)
{
	t_point		cell;
	t_dpoint	dest;

	dest = (t_dpoint){vars->player->pos.x + mov.x, vars->player->pos.y + mov.y};
	cell.y = vars->player->pos.y / CELL_SIZE;
	if (mov.x > 0)
		cell.x = dest.x / CELL_SIZE +.1;
	else
		cell.x = dest.x / CELL_SIZE -.1;
	if (vars->map->data[cell.y][cell.x] == '1')
		dest.x = vars->player->pos.x;
	cell.x = vars->player->pos.x / CELL_SIZE;
	if (mov.y > 0)
		cell.y = dest.y / CELL_SIZE +.1;
	else
		cell.y = dest.y / CELL_SIZE -.1;
	if (vars->map->data[cell.y][cell.x] == '1')
		dest.y = vars->player->pos.y;
	vars->player->pos = dest;
	fill_near(cell, 3, vars->map);
}

void	move(t_vars *vars)
{
	t_dpoint	p;
	double		ang;

	if (vars->inputs[ROTATE_L])
		vars->player->angle -= 0.01;
	if (vars->inputs[ROTATE_R])
		vars->player->angle += 0.01;
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
