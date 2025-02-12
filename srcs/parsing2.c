/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/12 11:24:28 by rsebasti         ###   ########.fr       */
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

int	check_style(t_map *map)
{
	if (map->style[0] == NULL)
		return (ft_puterror("NO not specified", 1));
	if (invalid_style(map->style[0]))
		return (ft_puterror("NO invalid", 1));
	if (map->style[1] == NULL)
		return (ft_puterror("SO not specified", 1));
	if (invalid_style(map->style[1]))
		return (ft_puterror("SO invalid", 1));
	if (map->style[2] == NULL)
		return (ft_puterror("WE not specified", 1));
	if (invalid_style(map->style[2]))
		return (ft_puterror("WE invalid", 1));
	if (map->style[3] == NULL)
		return (ft_puterror("EA not specified", 1));
	if (invalid_style(map->style[3]))
		return (ft_puterror("EA invalid", 1));
	if (map->style[4] == NULL)
		return (ft_puterror("F not specified", 1));
	if (invalid_style(map->style[4]))
		return (ft_puterror("F invalid", 1));
	if (map->style[5] == NULL)
		return (ft_puterror("C not specified", 1));
	if (invalid_style(map->style[5]))
		return (ft_puterror("C invalid", 1)); 
	return (0);
}

void	check_block(char **map, t_point cur, int *count, t_map *tmap)
{
	if (map[cur.y][cur.x] == ' ' || map[cur.y][cur.x] == '2' || *count == -1)
		return ;
	if ((map[cur.y][cur.x] == '0' || map[cur.y][cur.x] == 'N'
		|| map[cur.y][cur.x] == 'W' || map[cur.y][cur.x] == 'E'
		|| map[cur.y][cur.x] == 'S')
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
			if (map[x][y] == '0' || map[x][y] == '1')
				counter[0]++;
			if (map[x][y] == 'N' || map[x][y] == 'S'
				|| map[x][y] == 'E' || map[x][y] == 'W')
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
	int	count;
	t_point	player;

	if (check_style(tmap) == 1)
		return (1);
	count = elem_count(map);
	if (count == -1)
		return (ft_puterror("too many player", 1));
	player = find_player(map);
	if (player.x == -1)
		return (ft_puterror("no player", 1));
	check_block(map, player, &count, tmap);
	if (count == -1)
		return (ft_puterror("invalid map, floor near void", 1));
	if (count > 0)
		return (ft_puterror("invalid map, cutted by void", 1));
	return (0);
}
