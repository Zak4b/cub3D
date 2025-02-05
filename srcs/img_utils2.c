/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 11:35:22 by asene             #+#    #+#             */
/*   Updated: 2025/02/05 13:54:12 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

void	free_image(t_vars *vars, t_img *img)
{
	mlx_destroy_image(vars->mlx, img->img);
	free(img);
}

void	clear_array_img(t_vars *vars, t_img **imgs)
{
	t_img	**arr;

	arr = imgs;
	while (*imgs)
	{
		free_image(vars, *imgs);
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

t_img	*load_img(t_vars *vars, char *path)
{
	t_img	*img;

	img = ft_calloc(1, sizeof(t_img));
	img->img = mlx_xpm_file_to_image(vars->mlx, path,
			&(img->width), &(img->height));
	if (img->img != NULL)
		img->addr = mlx_get_data_addr(img->img, &(img->bpp),
				&(img->line_length), &(img->endian));
	return (img);
}

t_img	**load_sprites(t_vars *vars, char *path, unsigned int count)
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
		imgs[i] = load_img(vars, full_path);
		free(full_path);
		free(nbptr);
		i++;
	}
	imgs[i] = NULL;
	return (imgs);
}
