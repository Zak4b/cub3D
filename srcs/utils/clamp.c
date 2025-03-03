/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clamp.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 16:55:47 by asene             #+#    #+#             */
/*   Updated: 2025/02/15 16:59:05 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	clamp_int(int n, int min, int max)
{
	if (n > max)
		n = max;
	if (n < min)
		n = min;
	return (n);
}
