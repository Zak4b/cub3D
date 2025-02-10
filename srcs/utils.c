/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rsebasti <rsebasti@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/10 15:39:25 by rsebasti          #+#    #+#             */
/*   Updated: 2025/02/10 15:46:39 by rsebasti         ###   ########.fr       */
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
