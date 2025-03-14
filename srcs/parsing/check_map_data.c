/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_data.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 14:30:03 by asene             #+#    #+#             */
/*   Updated: 2025/03/14 11:08:28 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
			if (ft_strchr("01D", map[x][y]))
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

char	**dup_array(char **array, int size)
{
	char	**new;
	int		i;

	i = 0;
	new = ft_calloc(size + 1, sizeof(char *));
	while (i < size)
	{
		new[i] = ft_strdup(array[i]);
		i++;
	}
	return (new);
}

int	check_map_data(t_map *map)
{
	int		count;
	char	**data_dup;

	count = elem_count(map->data);
	if (count == -1)
		return (ft_puterror("too many player", ERROR));
	data_dup = dup_array(map->data, map->height);
	check_block(data_dup, map->start_pos, &count, map);
	free_split(data_dup);
	if (count == -1)
		return (ft_puterror("invalid map, floor near void", ERROR));
	if (count > 0)
		return (ft_puterror("invalid map, cutted by void", ERROR));
	return (0);
}
