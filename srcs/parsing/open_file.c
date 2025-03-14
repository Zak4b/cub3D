/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_file.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/10 10:55:50 by asene             #+#    #+#             */
/*   Updated: 2025/03/14 11:42:00 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"
#define FILE_EXT ".cub"

int	open_file(char *path)
{
	int	index;
	int	fd;

	index = ft_strlen(path) - ft_strlen(FILE_EXT);
	if (index < 0 || ft_strcmp(path + index, FILE_EXT))
		return (-1);
	fd = open(path, O_RDONLY);
	return (fd);
}
