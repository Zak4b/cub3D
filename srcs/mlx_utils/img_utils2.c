/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2025/02/14 19:51:22 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	free_image(t_mlx *mlx, t_img *img)
{
	mlx_destroy_image(mlx->instance, img->img);
	free(img);
}

void	clear_array_img(t_mlx *mlx, t_img **imgs)
{
	t_img	**arr;

	arr = imgs;
	while (*imgs)
	{
		free_image(mlx, *imgs);
		imgs++;
	}
	free(arr);
}

t_img	*new_image(t_mlx *mlx, int width, int height)
{
	t_img	*i;

	i = ft_calloc(1, sizeof(t_img));
	i->img = mlx_new_image(mlx->instance, width, height);
	i->addr = mlx_get_data_addr(i->img,
			&i->bpp,
			&i->line_length,
			&i->endian);
	i->width = width;
	i->height = height;
	ft_lstadd_front(&mlx->img_list, ft_lstnew(i));
	return (i);
}

t_img	*load_img(t_mlx *mlx, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	img->img = mlx_xpm_file_to_image(mlx->instance, path,
			&(img->width), &(img->height));
	if (img->img != NULL)
	{
		img->addr = mlx_get_data_addr(img->img, &(img->bpp),
				&(img->line_length), &(img->endian));
		ft_lstadd_front(&mlx->img_list, ft_lstnew(img));
	}
	return (img);
}

t_img	**load_sprites(t_mlx *mlx, char *path, unsigned int count)
{
	unsigned int	i;
	char			*full_path;
	char			*nbptr;
	t_img			**imgs;

	imgs = ft_calloc(count + 1, sizeof(t_img *));
	i = 0;
	while (i < count)
	{
		nbptr = ft_itoa(i);
		full_path = ft_strnjoin((char *[]){path, nbptr, ".xpm"}, 3, "");
		imgs[i] = load_img(mlx, full_path);
		free(full_path);
		free(nbptr);
		i++;
	}
	imgs[i] = NULL;
	return (imgs);
}
