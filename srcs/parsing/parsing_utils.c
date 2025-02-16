/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 10:00:31 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/16 17:48:57 by rsebasti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	invalid_style(char *style)
{
	int	fd;

	if (style)
	{
		return (0); // delete later
		fd = open(style, O_RDONLY);
		if (fd == -1)
			return (1);
		close(fd);
		return (0);
	}
	else
		return (1);
}
