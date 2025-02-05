/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2025/02/05 13:53:54 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	dst = img->addr
		+ (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

void	put_image(t_img *dest, t_img *img, int x0, int y0)
{
	int	x;
	int	y;
	int	*img_data;
	int	color;

	img_data = (int *)img->addr;
	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = img_data[y * (img->line_length / 4) + x];
			if ((color >> 24 & 0xFF) == 0)
				put_pixel(dest, x + x0, y + y0, color);
			x++;
		}
		y++;
	}
}
