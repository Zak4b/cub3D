/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterror.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:54:29 by asene             #+#    #+#             */
/*   Updated: 2025/02/15 16:59:07 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cub3D.h>

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
