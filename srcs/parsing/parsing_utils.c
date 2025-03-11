/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:00:31 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/11 12:50:39 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	invalid_style(char *style)
{
	int	fd;

	if (style)
	{
		fd = open(style, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
		return (0);
	}
	return (1);
}

int	check_style(t_map *map, t_style type)
{
	char	*type_string;
	char	*error_msg;

	error_msg = NULL;
	if (map->style[type] == NULL)
		error_msg = "not specified";
	else if (invalid_style(map->style[type]))
		error_msg = "is invalid";
	if (error_msg)
	{
		if (type == NORTH)
			type_string = "NO";
		else if (type == SOUTH)
			type_string = "SO";
		else if (type == EAST)
			type_string = "EA";	
		else if (type == WEST)
			type_string = "WE";
		else if (type == CEILING)
			type_string = "C";
		else
			type_string = "F";
		return (ft_fprintf(2, "%s %s\n", type_string, error_msg), 1);
	}
	return (0);
}

int	convert_rgb(t_map *map, int type)
{
	char	**splited;
	int		color;

	splited = ft_split(map->style[type], ',');
	if (!splited[1] || !splited[2])
		return (-1);
	color = (ft_atoi(splited[0]) << 16) | (ft_atoi(splited[1]) << 8);
	color = color | ft_atoi(splited[2]);
	free_split(splited);
	return (color);
}
