/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_background.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:36:24 by asene             #+#    #+#             */
/*   Updated: 2025/02/16 10:06:01 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static void	draw_ceiling(t_vars *vars)
{
	int	i;

	i = 0;
	while (i < W_HEIGHT / 2)
		draw_hline(vars->buffer, (t_point){0, i++}, W_WIDTH, 0x82733f);
}

static void	draw_floor(t_vars *vars)
{
	int	i;
	int	color;

	i =  W_HEIGHT / 2;
	while (i < W_HEIGHT)
	{
		color = 0x736a3e;
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