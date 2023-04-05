/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:32:42 by jledesma          #+#    #+#             */
/*   Updated: 2022/04/26 14:02:24 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Removes and frees the given node 'lst' and all the consecutive
** ones of that node, using the function 'del' and free(3).
** At the end, the pointer to the list must be NULL.
*/

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;

	if (lst && del)
	{
		while (*lst)
		{
			tmp = (*lst)->next;
			(*del)((*lst)->content);
			free(*lst);
			*lst = tmp;
		}
	}
}
