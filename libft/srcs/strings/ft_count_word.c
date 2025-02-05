/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:25:50 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 19:23:34 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Counts the number of words in `str`, using `c` as the delimiter
int	ft_count_word(char const *str, char c)
{
	int	wc;

	if (!str)
		return (0);
	wc = 0;
	while (*str)
	{
		while (*str && *str == c)
			str++;
		if (*str)
			wc++;
		while (*str && *str != c)
			str++;
	}
	return (wc);
}
