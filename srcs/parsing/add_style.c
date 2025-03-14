/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_style.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/14 10:12:06 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

static char	**get_style_adress(t_map *map, char **line)
{
    const char		*keys[] = {"NO", "SO", "WE", "EA", "F", "C"};
	const t_style	types[] = {NORTH, SOUTH, WEST, EAST, FLOOR, CEILING};
	int				i;
	char			**dest;
	size_t			key_len;
	
	i = 0;
	dest = NULL;
    while (i < (int) (sizeof(keys) / sizeof(keys[0])))
	{
		key_len = ft_strlen(keys[i]);
        if (ft_strncmp(*line, keys[i], key_len) == 0
			&& ft_isspace(*(*line + key_len)))
		{
            dest = &map->style[types[i]];
            *line = *line + key_len;
            break;
        }
		i++;
    }
	return (dest);
}

int	add_style(t_map *map, char *line)
{
	char	**dest;

	dest = get_style_adress(map, &line);
	if (!dest)
		return (1);
	if (*dest)
		free(*dest);
	while (*line && ft_isspace(*line))
		line++;
	if (line[ft_strlen(line) - 1] == '\n')
		line[ft_strlen(line) - 1] = '\0';
	*dest = ft_strdup(line);
	return (0);
}

