/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:24:13 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/10 15:38:45 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	line_checker(char *line)
{
	int	i;

	i = 0;
	if (ft_strchr(line, '1') == NULL)
		return (-1);
	while (line[i] == ' ')
		i++;
	if (line[i] != '1')
		return (0);
	while (line[i] == '1')
		i++;
	if (line[i] == '\n')
		return (2);
	while (line[i])
	return (1);
}
