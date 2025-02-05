/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 14:47:24 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 15:56:01 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Write 'str' to file descriptor 'fd'
void	ft_putstr_fd(char *str, int fd)
{
	write(fd, str, ft_strlen(str));
}
