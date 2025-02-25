/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 12:27:44 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/25 14:32:49 by rsebasti         ###   ########.fr       */
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

	map = malloc(sizeof(char *) * (size + 1));
	if (map == NULL)
		return (NULL);
	i = 0;
	while (lmap)
	{
		map[i] = line_dup((char *) lmap->content, width);
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
	char	*content;

	cursor = lmap;
	while (cursor)
	{
		i = 0;
		if (cursor->content)
		{
			content = (char *) cursor->content;
			while (content[i])
			{
				if (ft_strchr(" D01NSEW\n", content[i]) == NULL)
					return (ft_puterror("invalid character in map", ERROR));
				i++;
			}
		}
		cursor = cursor->next;
	}
	return (0);
}

int	init_map(t_map *map, int fd)
{
	int		i;
	t_list	*lmap;

	lmap = NULL;
	map->style = malloc(sizeof(char *) * 7);
	create_list_map(fd, &lmap, map);
	map->style[6] = NULL;
	if (map->width == 0)
		return (ft_lstclear(&lmap, free), ft_puterror("invalid map no floor / wall", ERROR));
	if (map->height <= 2 || map->width <= 2)
		return (ft_lstclear(&lmap, free), ft_puterror("map too small", ERROR));
	if (map_incorrect(lmap))
		return (ft_lstclear(&lmap, free), 1);
	map->data = create_map(lmap, map->height, map->width);
	i = 0;
	while (map->data[i])
	{
		ft_printf("%s\n", map->data[i]);
		i++;
	}
	map->discovered = create_map(lmap, map->height, map->width);
	if (checker(create_map(lmap, map->height, map->width), map))
		return (ft_lstclear(&lmap, free), 1);
	ft_lstclear(&lmap, free);
	return (0);
}
