/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:47:01 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:00:41 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Write `c` to file descriptor `fd`
void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
