/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_after.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 16:46:09 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 19:23:03 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Add `new` after the node `lst`
void	ft_lstadd_after(t_list **lst, t_list *new)
{
	t_list	*next_node;

	if (*lst == NULL)
	{
		*lst = new;
		return ;
	}
	next_node = (*lst)->next;
	(*lst)->next = new;
	new->prev = *lst;
	new->next = next_node;
	if (next_node)
		next_node->prev = new;
}
