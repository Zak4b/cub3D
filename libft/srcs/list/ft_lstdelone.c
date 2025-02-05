/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asene <asene@student.42perpignan.fr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 15:11:12 by asene             #+#    #+#             */
/*   Updated: 2025/02/01 16:04:44 by asene            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

// Delete a single node, applying `del` to its content
void	ft_lstdelone(t_list *lst, void (*del)(void*))
{
	if (del)
		del(lst->content);
	free(lst);
}
