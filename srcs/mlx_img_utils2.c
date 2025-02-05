/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_img_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2024/12/25 23:02:13 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <so_long.h>

void	free_image(t_game *game, t_img *img)
{
	mlx_destroy_image(game->mlx, img->img);
	free(img);
}

void	clear_array_img(t_game *game, t_img **imgs)
{
	t_img	**arr;

	arr = imgs;
	while (*imgs)
	{
		free_image(game, *imgs);
		imgs++;
	}
	free(arr);
}

t_img	*new_image(void *mlx, int width, int height)
{
	t_img	*i;

	i = ft_calloc(1, sizeof(t_img));
	i->img = mlx_new_image(mlx, width, height);
	i->addr = mlx_get_data_addr(i->img,
			&i->bpp,
			&i->line_length,
			&i->endian);
	i->width = width;
	i->height = height;
	return (i);
}
