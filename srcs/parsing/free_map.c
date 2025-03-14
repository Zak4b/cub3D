/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 15:47:09 by asene             #+#    #+#             */
/*   Updated: 2025/03/14 11:08:51 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_map(t_map *map)
{
	int	i;

	if (map->data)
		free_split(map->data);
	if (map->discovered)
		free_split(map->discovered);
	i = 0;
	while (i < 6)
	{
		if (map->style[i])
			free(map->style[i]);
		i++;
	}
	free(map);
}
