/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:09:22 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:06:42 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <stdint.h>

// Copies `n` bytes from `src` to `dest` handling overlaps safely
void	*ft_memmove(void *dest, const void *src, size_t n)
{
	uint8_t	*d;
	uint8_t	*s;

	if (dest == src)
		return (dest);
	if (dest <= src)
		return (ft_memcpy(dest, src, n));
	d = (uint8_t *)dest + n;
	s = (uint8_t *)src + n;
	while (n >= 8)
	{
		d -= 8;
		s -= 8;
		*(uint64_t *)d = *(const uint64_t *)s;
		n -= 8;
	}
	while (n-- > 0)
		*--d = *--s;
	return (dest);
}
