/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 10:31:59 by asene             #+#    #+#             */
/*   Updated: 2025/02/15 19:58:51 by asene            ###   ########.fr       */
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
	if (k == KEY_ALT)
		mlx_mouse_show(vars->mlx->instance, vars->mlx->window);
	if (k == KEY_ESC)
		mlx_loop_end(vars->mlx->instance);
	else
		set_input(vars, k, 1);
	return (0);
}

int	key_up_hook(int k, t_vars *vars)
{
	if (k == KEY_ALT)
		mlx_mouse_hide(vars->mlx->instance, vars->mlx->window);
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
	mlx_put_image_to_window(vars->mlx->instance, vars->mlx->window, vars->buffer->img, 0, 0);
	mlx_do_sync(vars->mlx->instance);
	return (1);
}
