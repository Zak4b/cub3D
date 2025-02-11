/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:25 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/11 15:09:57 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_strchrs(char *str, char *chrs)
{
	int	i;
	int	j;

	i = 0;
	if (str != NULL)
	{
		while (str[i])
		{
			j = 0;
			while (chrs[j])
			{
				if (str[i] == chrs[j])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

t_point	*find_player(char **map)
{
	int	x;
	int	y;

	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (ft_strchrs(&map[x][y], "NSEW"))
				return (NULL);
			y++;
		}
		x++;
	}
	return (NULL);
}

char	*line_dup(const char *src, int len)
{
	int		i;
	char	*dup;

	dup = malloc(sizeof(char) * (len + 1));
	if (dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		if (src[i] == '\n')
			dup[i] = ' ';
		else
			dup[i] = src[i];
		i++;
	}
	while (i < len)
	{
		dup[i] = ' ';
		i++;
	}
	dup[len] = '\0';
	return (dup);
}
