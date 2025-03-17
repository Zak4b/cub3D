/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2025/03/17 14:13:40 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	set_input(t_vars *vars, int key, int value)
{
	unsigned int			i;
	static const t_keymap	keymap[] = {
	{KEY_D, MOVE_R}, {KEY_A, MOVE_L},
	{KEY_W, MOVE_F}, {KEY_S, MOVE_B},
	{KEY_A_LEFT, ROTATE_L},	{KEY_A_RIGHT, ROTATE_R},
	{KEY_SHIFT, RUN}, {KEY_ALT, ALT}};

	i = 0;
	while (i < sizeof(keymap))
	{
		if (keymap[i].key == key)
			return (vars->inputs[keymap[i].input] = value, (void)0);
		i++;
	}
}

int	key_down_hook(int k, t_vars *vars)
{
	if (k == KEY_ESC)
		mlx_loop_end(vars->mlx->instance);
	if (k == KEY_P)
		vars->shadow = !vars->shadow;
	if (k == KEY_T)
	{
		vars->inputs[TORCH_T] = !vars->inputs[TORCH_T];
		vars->inputs[TORCH_STATE] = 0;	
	}
	if (k == KEY_SPACE)
		search_door(vars);
	else
		set_input(vars, k, 1);
	return (0);
}

int	key_up_hook(int k, t_vars *vars)
{
	set_input(vars, k, 0);
	return (0);
}

int	game_loop(t_vars *vars)
{
	move(vars);
	mouse_movement(vars);
	draw_background(vars);
	draw_walls(vars);
	print_minimap(vars);
	torch(vars);
	vars->inputs[TORCH_STATE]++;
	mlx_put_image_to_window(vars->mlx->instance,
		vars->mlx->window, vars->buffer->img, 0, 0);
	mlx_do_sync(vars->mlx->instance);
	return (1);
}
