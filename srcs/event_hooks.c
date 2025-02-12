/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_hooks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2025/02/12 14:24:25 by rsebasti         ###   ########.fr       */
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
		vars->player->pos.x += cos(vars->player->angle + ang);
		vars->player->pos.y += sin(vars->player->angle + ang);
	}
}

int	game_loop(t_vars *vars)
{
	mouse_movement(vars);
	move(vars);
	render(vars);
	return (1);
}
