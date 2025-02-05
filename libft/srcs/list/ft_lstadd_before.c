/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_before.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:46:09 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 19:22:59 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Add `new` before the node `lst`
void	ft_lstadd_before(t_list **lst, t_list *new)
{
	t_list	*prev_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	prev_node = (*lst)->prev;
	new->next = *lst;
	(*lst)->prev = new;
	new->prev = prev_node;
	if (prev_node)
		prev_node->next = new;
}
