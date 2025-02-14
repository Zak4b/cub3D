/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:25 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/14 02:36:32 by asene            ###   ########.fr       */
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

t_point	find_player(char **map)
{
	t_point	player;

	player.y = 0;
	while (map[player.y])
	{
		player.x = 0;
		while (map[player.y][player.x])
		{
			if (ft_strchr("NSEW", map[player.y][player.x]))
				return (player);
			player.x++;
		}
		player.y++;
	}
	player.x = -1;
	player.y = -1;
	return (player);
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

int	ft_puterror(char *str, t_error_type type)
{
	char	*prefix;

	if (type == 1)
		prefix = "\033[1;31mERROR: ";
	else
		prefix = "\033[1;33mWarning: ";
	ft_fprintf(2, "%s%s\033[0m\n", prefix, str);
	return (1);
}

int	clamp_int(int n, int min, int max)
{
	if (n > max)
		n = max;
	if (n < min)
		n = min;
	return (n);
}
