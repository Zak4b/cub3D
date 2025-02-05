/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:43:34 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:03:21 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Converts `nptr` to an interger (int)
int	ft_atoi(const char *nptr)
{
	long	result;
	int		sign;

	if (!nptr)
		return (0);
	result = 0;
	sign = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
		if (*(nptr++) == '-')
			sign = -1;
	while (ft_isdigit(*nptr))
		result = result * 10 + (*(nptr++) - '0');
	return ((int)result * sign);
}
