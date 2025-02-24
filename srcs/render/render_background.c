/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:36:24 by asene             #+#    #+#             */
/*   Updated: 2025/02/24 10:49:44 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_ceiling(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < W_HEIGHT / 2)
		draw_hline(vars->buffer, (t_point){0, i++}, W_WIDTH, vars->map->ceiling);
}

static void	draw_floor(t_vars *vars)
{
	int	i;
	int	color;

	i =  W_HEIGHT / 2;
	while (i < W_HEIGHT)
	{
		color = vars->map->floor;
		if (vars->shadow)
			color = color_shadowing(color,
					(W_HEIGHT / 2 - i) / (double)CELL_SIZE + SHADOWING);
		draw_hline(vars->buffer, (t_point){0, i}, W_WIDTH, color);
		i++;
	}
}

void	draw_background(t_vars *vars)
{
	draw_ceiling(vars);
	draw_floor(vars);
}