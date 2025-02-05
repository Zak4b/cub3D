/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfirst.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:45:00 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 19:22:53 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Returns the first node of `lst`
t_list	*ft_lstfirst(t_list *lst)
{
	while (lst && lst->prev)
		lst = lst->prev;
	return (lst);
}
