/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isspace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 17:35:21 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 15:07:28 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Checks for white-space characters
int	ft_isspace(int c)
{
	return (c == ' ' || (c >= 9 && c <= 13));
}
