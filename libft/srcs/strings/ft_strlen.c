/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:47:29 by asene             #+#    #+#             */
/*   Updated: 2024/11/04 13:47:29 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Returns the length of the string `s`
size_t	ft_strlen(const char *s)
{
	int	count;

	count = 0;
	if (s)
		while (s[count] != '\0')
			count++;
	return (count);
}
