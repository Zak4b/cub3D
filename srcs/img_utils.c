/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2025/02/12 20:21:25 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || y < 0 || x >= img->width || y >= img->height)
		return ;
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

int	get_img_pixel(t_img *img, int col_index, int row_index, int total_size)
{
	const int	*img_data = (int *)img->addr;
	
	return img_data[row_index * img->height / total_size * (img->line_length / 4) + col_index];	
}