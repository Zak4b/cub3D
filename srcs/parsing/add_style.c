/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/10 15:03:33 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	add_style(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO", INT_MAX))
		map->style[NORTH] = ft_substr(line + 3, 0, ft_strlen(line + 3) - 1);
	else if (ft_strnstr(line, "SO", INT_MAX))
		map->style[SOUTH] = ft_substr(line + 3, 0, ft_strlen(line + 3) - 1);
	else if (ft_strnstr(line, "WE", INT_MAX))
		map->style[WEST] = ft_substr(line + 3, 0, ft_strlen(line + 3) - 1);
	else if (ft_strnstr(line, "EA", INT_MAX))
		map->style[EAST] = ft_substr(line + 3, 0, ft_strlen(line + 3) - 1);
	else if (ft_strchr(line, 'F'))
		map->style[FLOOR] = ft_substr(line + 2, 0, ft_strlen(line + 2) - 1);
	else if (ft_strchr(line, 'C'))
		map->style[CEILING] = ft_substr(line + 2, 0, ft_strlen(line + 2) - 1);
	else
		return (1);
	return (0);
}

