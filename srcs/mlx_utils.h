/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 18:27:51 by asene             #+#    #+#             */
/*   Updated: 2025/02/14 18:46:21 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <mlx.h>

typedef struct s_img
{
	int		width;
	int		height;
	void	*img;
	char	*addr;
	int		bpp;
	int		line_length;
	int		endian;
}	t_img;

typedef struct s_mlx
{
	void	*instance;
	void	*window;
	t_list	*img_list;
}	t_mlx;

t_mlx	*t_mlx_init(unsigned int width, unsigned int height, char *title);
void	t_mlx_kill(t_mlx *mlx);

void	free_image(t_mlx *mlx, t_img *img);
void	clear_array_img(t_mlx *mlx, t_img **imgs);
t_img	*new_image(t_mlx *mlx, int width, int height);
t_img	*load_img(t_mlx *mlx, char *path);
t_img	**load_sprites(t_mlx *mlx, char *path, unsigned int count);

void	put_pixel(t_img *img, int x, int y, int color);
void	put_image(t_img *dest, t_img *img, int x0, int y0);
int		get_pixel(t_img *img, int x, int y);