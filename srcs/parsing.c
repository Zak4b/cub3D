/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:27:44 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/10 15:23:57 by rsebasti         ###   ########.fr       */
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

int	create_list_map(int fd, t_list *lmap, t_map *map)
{
	char	*line;

	line = get_next_line(fd);
	map->style = malloc(sizeof(char*) * 6);
	while (line)
	{
		if (ft_strnstr(line, "NO", INT_MAX))
			map->style[0] = ft_strdup(ft_strnstr(line, "NO", INT_MAX));
		else if (ft_strnstr(line, "SO", INT_MAX))
			map->style[1] = ft_strdup(ft_strnstr(line, "SO", INT_MAX));
		else if (ft_strnstr(line, "WE", INT_MAX))
			map->style[2] = ft_strdup(ft_strnstr(line, "WE", INT_MAX));
		else if (ft_strnstr(line, "EA", INT_MAX))
			map->style[3] = ft_strdup(ft_strnstr(line, "EA", INT_MAX));
		else if (ft_strchr(line, 'F'))
			map->style[4] = ft_strdup(line + 1);
		else if (ft_strchr(line, 'C'))
			map->style[5] = ft_strdup(line + 1);
		else
			ft_lstadd_back(lmap, ft_lstnew(ft_strdup(line)));
		free(line);
		line = get_next_line(fd);
	}
	return (ft_lstsize(lmap));
}

char	**create_map(t_list *lmap, int size)
{
	char	**map;
	int		i;

	map = malloc(sizeof(char*) * (size + 1));
	if (map != NULL)
		return (NULL);
	i = 0;
	while (lmap)
	{
		map[i] = ft_strdup(lmap->content);
		i++;
		lmap = lmap->next;
	}
	map[i][0] = '\0';
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
		if ()
		cursor = cursor->next;
	}
	return (0);
}

int	init_map(t_map *map, char *file)
{
	int		fd;
	t_list	*lmap;
	int		size;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (0); // incorrect map file
	lmap = NULL;
	size = create_list_map(fd, lmap, map);
	if (size <= 2)
		return (0); // incorrect map
	if (map_incorrect(lmap, map))
		return (end_parsing);
	map->data = create_map(lmap, size); 
	ft_lstclear(lmap, free);
	return (1);
}
