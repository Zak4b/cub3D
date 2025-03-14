/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:00:31 by rsebasti          #+#    #+#             */
/*   Updated: 2025/03/14 11:05:15 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*get_style_string(t_style type)
{
	char	*type_string;

	if (type == NORTH)
		type_string = "NO";
	else if (type == SOUTH)
		type_string = "SO";
	else if (type == EAST)
		type_string = "EA";
	else if (type == WEST)
		type_string = "WE";
	else if (type == CEILING)
		type_string = "C ";
	else if (type == FLOOR)
		type_string = "F ";
	else
		type_string = "";
	return (type_string);
}

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
	else
	{
		if ((type == CEILING && map->ceiling == -1)
			|| (type == FLOOR && map->floor == -1))
			error_msg = "is invalid";
		else if (type != CEILING && type != FLOOR
			&& invalid_style(map->style[type]))
			error_msg = "is invalid";
	}
	if (error_msg)
	{
		type_string = get_style_string(type);
		error_msg = ft_strnjoin((char *[]){type_string, error_msg}, 2, " ");
		ft_puterror(error_msg, ERROR);
		free(error_msg);
		return (1);
	}
	return (0);
}

int	convert_rgb(t_map *map, int type)
{
	char	**splited;
	int		color;

	if (map->style[type] == NULL)
		return (-1);
	splited = ft_split(map->style[type], ',');
	if (!splited[1] || !splited[2])
		return (free_split(splited), -1);
	color = (ft_atoi(splited[0]) << 16) | (ft_atoi(splited[1]) << 8);
	color = color | ft_atoi(splited[2]);
	free_split(splited);
	return (color);
}
