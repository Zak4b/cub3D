/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   torch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 14:05:22 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/17 14:22:30 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	show_torch(t_vars *vars, int nb, t_img **kind, int i)
{
	put_image_resized(vars->buffer, kind[(i) % nb],
		W_WIDTH / 3, W_HEIGHT - vars->torch[0]->height * TORCH_SIZE);
}

void	torch(t_vars *vars)
{
	if (!vars->inputs[TORCH_T])
	{
		if (vars->inputs[TORCH_STATE] < 9)
			show_torch(vars, 3, vars->torch_start,
				vars->inputs[TORCH_STATE] / 3);
		else
			show_torch(vars, 6, vars->torch,
				vars->inputs[TORCH_STATE] / 5);
	}
	else
	{
		if (vars->inputs[TORCH_STATE]++ < 30)
			show_torch(vars, 6, vars->torch_end, vars->inputs[TORCH_STATE] / 5);
	}
}
