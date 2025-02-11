/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/11 13:08:58 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	add_style(t_map *map, char *line)
{
	if (ft_strnstr(line, "NO", INT_MAX))
		map->style[0] = ft_strdup(line + 3);
	else if (ft_strnstr(line, "SO", INT_MAX))
		map->style[1] = ft_strdup(line + 3);
	else if (ft_strnstr(line, "WE", INT_MAX))
		map->style[2] = ft_strdup(line + 3);
	else if (ft_strnstr(line, "EA", INT_MAX))
		map->style[3] = ft_strdup(line + 3);
	else if (ft_strchr(line, 'F'))
		map->style[4] = ft_strdup(line + 2);
	else if (ft_strchr(line, 'C'))
		map->style[5] = ft_strdup(line + 2);	
	else
		return (1);
	return (0);
}
