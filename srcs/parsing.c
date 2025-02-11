/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:27:44 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/11 15:08:06 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	end_parsing(int fd, t_list *map, char *line)
{
	close(fd);
	get_next_line(fd);
	if (map)
		ft_lstclear(&map, free);
	if (line)
		free(line);
	return (0);
}

void	create_list_map(int fd, t_list **lmap, t_map *map)
{
	char	*line;
	int		len;

	line = get_next_line(fd);
	map->style = malloc(sizeof(char*) * 6);
	while (line)
	{
		if (add_style(map, line))
		{
			ft_lstadd_back(lmap, ft_lstnew(ft_strdup(line)));
			if (ft_strchrs(line, "10") && (int) ft_strlen(line) > len)
				len = ft_strlen(line);
		}
		free(line);
		line = get_next_line(fd);
	}
	map->height = ft_lstsize(*lmap);
	map->width = len;
}

char	**create_map(t_list *lmap, int size, int width)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char*) * (size + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (lmap)
	{
		map[i] = line_dup((char*) lmap->content, width);
		i++;
		lmap = lmap->next;
	}
	map[i] = NULL;
	return (map);
}

int	map_incorrect(t_list *lmap, t_map *map)
{
	int	i;
	t_list	*cursor;

	cursor = lmap;
	i = 0;
	while (i < 6)
	{
		if (map->style[i] == NULL)
			return (1); // missing map style
		i++;
	}
	while (cursor)
	{
		cursor = cursor->next;
	}
	return (0);
}

int	init_map(t_map *map, int fd)
{
	t_list	*lmap;

	lmap = NULL;
	create_list_map(fd, &lmap, map);
	if (map->height <= 2)
		return (0); // incorrect map
	map->data = create_map(lmap, map->height, map->width);
	int	i = 0;
	while (map->data[i])
	{
		ft_printf("%s\n", map->data[i]);
		i++;
	}
	ft_lstclear(&lmap, free);
	return (1);
}
