/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 11:04:53 by asene             #+#    #+#             */
/*   Updated: 2025/03/10 15:05:25 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#include "parsing.h"

t_map	*read_file(int fd)
{
	char	*line;
	t_list	*lst;
	t_map	*map;

	lst = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		ft_lstadd_back(&lst, ft_lstnew(line));
	}
	close(fd);
	get_next_line(fd);
	map = list_to_map(lst);
	ft_lstclear(&lst, free);
	return (map);
}
