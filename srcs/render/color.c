/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 21:35:29 by asene             #+#    #+#             */
/*   Updated: 2025/02/24 09:41:15 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	color_shadowing(int color, double distance)
{
	double			shadowing;
	unsigned char	red;
	unsigned char	green;
	unsigned char	blue;

	shadowing = 1 - (distance / SHADOWING);
	red = clamp_int((int)((color >> 16 & 255) * shadowing), 0, 255);
	green = clamp_int((int)((color >> 8 & 255) * shadowing), 0, 255);
	blue = clamp_int((int)((color & 255) * shadowing), 0, 255);
	return (red << 16 | green << 8 | blue);
}