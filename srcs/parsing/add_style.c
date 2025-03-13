/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/13 19:29:58 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	add_style(t_map *map, char *line)
{
    const char		*keys[] = {"NO", "SO", "WE", "EA", "F", "C"};
	const t_style	types[] = {NORTH, SOUTH, WEST, EAST, FLOOR, CEILING};
	int				i;
	char			**dest;

	i = 0;
	dest = NULL;
    while (i < (int) (sizeof(keys) / sizeof(keys[0])))
	{
        if (ft_strncmp(line, keys[i], ft_strlen(keys[i])) == 0)
		{
            dest = &map->style[types[i]];
            line += ft_strlen(keys[i]);
            break;
        }
		i++;
    }
	if (!dest)
		return (1);
	while (*line && ft_isspace(*line))
		line++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*dest = ft_strdup(line);
	return (0);
}

