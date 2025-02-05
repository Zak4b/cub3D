/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnjoin.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:55:36 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:00:05 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

static unsigned int	ft_strnjoin_len(char **strs, unsigned int size, char *sep)
{
	unsigned int	i;
	unsigned int	len;

	len = 1;
	i = 0;
	while (i < size)
		len += ft_strlen(strs[i++]);
	if (size != 0)
		len += (size - 1) * ft_strlen(sep);
	return (len);
}

// Joins `size` strings from `strs` into a single string, separated by `sep`
char	*ft_strnjoin(char **strs, unsigned int size, char *sep)
{
	unsigned int	i;
	unsigned int	j;
	unsigned int	len;
	char			*result;

	len = ft_strnjoin_len(strs, size, sep);
	result = ft_calloc(len, sizeof(char));
	i = 0;
	j = 0;
	while (i < size)
	{
		if (i != 0)
			j += ft_strlcpy(&result[j], sep, len - j);
		j += ft_strlcpy(&result[j], strs[i++], len - j);
	}
	return (result);
}
