/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lines.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:38:16 by asene             #+#    #+#             */
/*   Updated: 2025/02/14 18:38:51 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	draw_vline(t_img *dest, t_point p, int h, int color)
{
	int	i;

	i = 0;
	while (i < h)
		put_pixel(dest, p.x, p.y + i++, color);
}

void	draw_hline(t_img *dest, t_point p, int l, int color)
{
	int	i;

	i = 0;
	while (i < l)
		put_pixel(dest, p.x + i++, p.y, color);
}