/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:50:08 by asene             #+#    #+#             */
/*   Updated: 2025/02/11 16:18:44 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D.h"

typedef struct s_cast_data
{
	t_dpoint	start;
	double		angle;
	double		tan_angle;
	t_dpoint	step;
	t_dpoint	v_hit;
	t_dpoint	h_hit;
}	t_cast_data;

int			in_map(t_map *map, int x, int y);

int			check_collide(t_map *map, int x, int y);

t_cast_data	calc_cast(t_dpoint start, double angle);