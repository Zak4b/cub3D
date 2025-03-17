/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2025/03/17 14:23:55 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
	dst = img->addr
		+ (y * img->line_length + x * (img->bpp / 8));
	*(int *)dst = color;
}

int	get_pixel(t_img *img, int x, int y)
{
	const int	*img_data = (int *)img->addr;

	return (img_data[y * (img->line_length / 4) + x]);
}

void	put_resized_pixel(t_img *dest, int offx, int offy, int color)
{
	int		y;
	int		x;

	y = 0;
	while (y < TORCH_SIZE)
	{
		x = 0;
		while (x < TORCH_SIZE)
		{
			put_pixel(dest, offx + x, offy + y, color);
			x++;
		}
		y++;
	}
}

void	put_image(t_img *dest, t_img *img, int x0, int y0)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel(img, x, y);
			if ((color >> 24 & 0xFF) == 0)
				put_pixel(dest, x + x0, y + y0, color);
			x++;
		}
		y++;
	}
}

void	put_image_resized(t_img *dest, t_img *img, int x0, int y0)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < img->height)
	{
		x = 0;
		while (x < img->width)
		{
			color = get_pixel(img, x, y);
			if ((color >> 24 & 0xFF) == 0)
				put_resized_pixel(dest, x * TORCH_SIZE + x0,
					y * TORCH_SIZE + y0, color);
			x++;
		}
		y++;
	}
}
