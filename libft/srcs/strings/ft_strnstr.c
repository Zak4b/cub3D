/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:58 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:08:49 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Searches for `needle` in `str` within `n` characters
char	*ft_strnstr(const char *str, const char *needle, size_t n)
{
	size_t	i;
	size_t	needle_len;

	if (*needle == '\0')
		return ((char *)str);
	i = 0;
	needle_len = ft_strlen(needle);
	if (n < needle_len)
		return (NULL);
	while (str[i] && i < n - needle_len + 1)
	{
		if (ft_strncmp(str + i, needle, needle_len) == 0)
			return ((char *)str + i);
		i++;
	}
	return (NULL);
}
