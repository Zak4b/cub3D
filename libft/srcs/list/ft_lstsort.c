/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 17:01:37 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 19:17:40 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

void	ft_lstsort(t_list *lst, int (*fcmp)(t_list *a, t_list *b))
{
	t_list		*start;
	size_t		len;
	size_t		last;

	if (!lst)
		return ;
	start = lst;
	len = ft_lstsize(lst);
	while (len)
	{
		lst = start;
		last = len--;
		while (lst->next && last--)
		{
			if (fcmp(lst, lst->next) > 0)
				ft_memswap(&(lst->content), &(lst->next->content));
			lst = lst->next;
		}
	}
}