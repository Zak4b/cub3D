/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:27:44 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/12 12:20:50 by rsebasti         ###   ########.fr       */
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
	map->style[0] = NULL;
	map->style[1] = NULL;
	map->style[2] = NULL;
	map->style[3] = NULL;
	map->style[4] = NULL;
	map->style[5] = NULL;
	len = 0;
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

int	map_incorrect(t_list *lmap)
{
	t_list	*cursor;
	int		i;
	char 	*content;

	cursor = lmap;
	while (cursor)
	{
		i = 0;
		if (cursor->content)
		{
			content = (char *) cursor->content;
			while (content[i])
			{
				if (ft_strchr(" 01NSEW\n", content[i]) == NULL)
					return (ft_puterror("invalid character in map", 1));
				i++;
			}
		}
		cursor = cursor->next;
	}
	return (0);
}

int	init_map(t_map *map, int fd)
{
	t_list	*lmap;

	lmap = NULL;
	create_list_map(fd, &lmap, map);
	if (map->width == 0)
		return (ft_puterror("invalid map no floor / wall", 1));
	if (map->height <= 2 || map->width <= 2)
		return (ft_puterror("map too small", 1));
	if (map_incorrect(lmap))
		return (1);
	map->data = create_map(lmap, map->height, map->width);
	int	i = 0;
	while (map->data[i])
	{
		ft_printf("%s\n", map->data[i]);
		i++;
	}
	checker(create_map(lmap, map->height, map->width), map);
	ft_lstclear(&lmap, free);
	return (0);
}
