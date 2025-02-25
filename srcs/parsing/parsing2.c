/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/25 10:39:28 by rsebasti         ###   ########.fr       */
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

int	check_styles(t_map *map)
{
	if (check_style(map, NORTH) || check_style(map, SOUTH)
		|| check_style(map, EAST) || check_style(map, WEST))
		return (1);
	map->ceiling = convert_rgb(map, CEILING);
	map->floor = convert_rgb(map, FLOOR);
	if (map->ceiling == -1 || map->floor == -1)
		return (1);
	return (0);
}

void	check_block(char **map, t_point cur, int *count, t_map *tmap)
{
	if (map[cur.y][cur.x] == ' ' || map[cur.y][cur.x] == '2' || *count == -1)
		return ;
	if (ft_strchr("D0NSEW", map[cur.y][cur.x])
		&& ((cur.x - 1 < 0 || cur.x + 1 >= tmap->width || cur.y - 1 < 0
		|| cur.y + 1 >= tmap->height) || (map[cur.y][cur.x - 1] == ' '
		|| map[cur.y][cur.x + 1] == ' ' || map[cur.y - 1][cur.x] == ' '
		|| map[cur.y + 1][cur.x] == ' ')))
	{
		*count = -1;
		return ;
	}
	*count = *count - 1;
	map[cur.y][cur.x] = '2';
	if (cur.x - 1 >= 0)
		check_block(map, (t_point){cur.x - 1, cur.y}, count, tmap);
	if (cur.x + 1 < tmap->width)
		check_block(map, (t_point){cur.x + 1, cur.y}, count, tmap);
	if (cur.y - 1 >= 0)
		check_block(map, (t_point){cur.x, cur.y - 1}, count, tmap);
	if (cur.y + 1 < tmap->height)
		check_block(map, (t_point){cur.x, cur.y + 1}, count, tmap);
}

int	elem_count(char **map)
{
	int	x;
	int	y;
	int	counter[2];

	counter[0] = 0;
	counter[1] = 0;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '0' || map[x][y] == '1' || map[x][y] == 'D')
				counter[0]++;
			if (ft_strchr("NSEW", map[x][y]))
				counter[1]++;
			if (counter[1] > 1)
				return (-1);
			y++;
		}
		x++;
	}
	return (counter[0] + counter[1]);
}

int	checker(char **map, t_map *tmap)
{
	int		count;
	t_point	player;

	if (check_styles(tmap) == 1)
		return (free_split(map), 1);
	count = elem_count(map);
	if (count == -1)
		return (free_split(map), ft_puterror("too many player", ERROR));
	player = find_player(map);
	if (player.x == -1)
		return (free_split(map), ft_puterror("no player", ERROR));
	check_block(map, player, &count, tmap);
	if (count == -1)
		return (free_split(map),
			ft_puterror("invalid map, floor near void", ERROR));
	if (count > 0)
		return (free_split(map),
			ft_puterror("invalid map, cutted by void", ERROR));
	return (free_split(map), fill_near(player, 3, tmap), 0);
}
