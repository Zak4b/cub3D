/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:36:34 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:03:32 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static int	string_len_from_int(int n)
{
	int	len;

	if (n == 0)
		return (1);
	len = 0;
	if (n < 0)
	{
		n = n / -10;
		len += 2;
	}
	while (n > 0)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

// Converts `n` to a string
char	*ft_itoa(int n)
{
	long	long_n;
	int		i;
	char	*result;

	i = string_len_from_int(n);
	result = malloc(sizeof(char) * (i + 1));
	if (result == NULL)
		return (NULL);
	result[i] = '\0';
	long_n = n;
	if (n < 0)
	{
		long_n = -long_n;
		result[0] = '-';
	}
	else if (n == 0)
		result[0] = '0';
	while (long_n != 0)
	{
		result[--i] = long_n % 10 + '0';
		long_n = long_n / 10;
	}
	return (result);
}
