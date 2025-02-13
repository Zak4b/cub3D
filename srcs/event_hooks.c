/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2025/02/13 11:16:54 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_input(t_vars *vars, int key, int value)
{
	int	*target;

	if (key == KEY_D)
		target = &vars->inputs[MOVE_R];
	else if (key == KEY_A)
		target = &vars->inputs[MOVE_L];
	else if (key == KEY_W)
		target = &vars->inputs[MOVE_F];
	else if (key == KEY_S)
		target = &vars->inputs[MOVE_B];
	else if (key == KEY_A_LEFT)
		target = &vars->inputs[ROTATE_L];
	else if (key == KEY_A_RIGHT)
		target = &vars->inputs[ROTATE_R];
	else if (key == KEY_SHIFT)
		target = &vars->inputs[RUN];
	else
		return ;
	*target = value;
}

int	key_down_hook(int k, t_vars *vars)
{
	if (k == KEY_ESC)
		close_window(vars);
	else
		set_input(vars, k, 1);
	return (0);
}

int	key_up_hook(int k, t_vars *vars)
{
	set_input(vars, k, 0);
	return (0);
}

int	close_window(t_vars *vars)
{
	mlx_do_key_autorepeaton(vars->mlx);
	mlx_destroy_window(vars->mlx, vars->mlx_win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free(vars->player);
	exit(EXIT_SUCCESS);
	return (0);
}

void	move_player(t_vars *vars, t_dpoint mov)
{
	t_point		cell;
	t_dpoint	dest;

	dest = (t_dpoint){vars->player->pos.x + mov.x, vars->player->pos.y + mov.y};
	if (mov.x > 0)
		cell = (t_point){dest.x / CELL_SIZE +.1, vars->player->pos.y / CELL_SIZE};
	else
		cell = (t_point){dest.x / CELL_SIZE -.1, vars->player->pos.y / CELL_SIZE};
	if (vars->map->data[cell.y][cell.x] == '1')
		dest.x = vars->player->pos.x;
	if (mov.y > 0)
		cell = (t_point){vars->player->pos.x / CELL_SIZE, dest.y / CELL_SIZE +.1};
	else
		cell = (t_point){vars->player->pos.x / CELL_SIZE, dest.y / CELL_SIZE -.1};
	if (vars->map->data[cell.y][cell.x] == '1')
		dest.y = vars->player->pos.y;
	vars->player->pos = dest;
}

void	move(t_vars *vars)
{
	t_dpoint	p;
	double		ang;

	p = (t_dpoint){0, 0};
	if (vars->inputs[ROTATE_L])
		vars->player->angle -= 0.01;
	if (vars->inputs[ROTATE_R])
		vars->player->angle += 0.01;
	if (vars->inputs[MOVE_F] || vars->inputs[MOVE_B] || vars->inputs[MOVE_L] || vars->inputs[MOVE_R])
	{
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
		p = (t_dpoint){cos(vars->player->angle + ang), sin(vars->player->angle + ang)};
		if (vars->inputs[RUN])
			p = (t_dpoint){p.x * 2, p.y * 2};
		move_player(vars, p);
	}
}

int	game_loop(t_vars *vars)
{
	move(vars);
	mouse_movement(vars);
	render(vars);
	return (1);
}
