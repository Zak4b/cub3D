/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:12:50 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:06:13 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include "stdint.h"

// Allocates and zeroes out memory for `count` elements of `size` bytes each
void	*ft_calloc(size_t count, size_t element_size)
{
	void	*ptr;
	size_t	total_size;

	if (SIZE_MAX / element_size < count)
		return (NULL);
	total_size = count * element_size;
	ptr = malloc(total_size);
	if (ptr != NULL)
		ft_bzero(ptr, total_size);
	return (ptr);
}
