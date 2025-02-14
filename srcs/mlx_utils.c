/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:10:27 by asene             #+#    #+#             */
/*   Updated: 2025/02/14 18:46:42 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

t_mlx	*t_mlx_init(unsigned int width, unsigned int height, char *title)
{
	t_mlx	*mlx;

	mlx = malloc(sizeof(t_mlx));
	mlx->instance = mlx_init();
	mlx->window = mlx_new_window(mlx->instance, width, height, title);
	mlx->img_list = NULL;
	return (mlx);
}

void	t_mlx_kill(t_mlx *mlx)
{
	t_list	*cursor;

	cursor = mlx->img_list;
	while (cursor)
	{
		free_image(mlx, cursor->content);
		cursor = cursor->next;
	}
	ft_lstclear(&mlx->img_list, NULL);
	if (mlx->window)
		mlx_destroy_window(mlx->instance, mlx->window);
	mlx_destroy_display(mlx->instance);
	free(mlx->instance);
	free(mlx);
}