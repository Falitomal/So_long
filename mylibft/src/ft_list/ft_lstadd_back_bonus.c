/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 12:19:40 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Add a new node in the end of 'lst'
*/

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*lastadd;

	if (*lst)
	{
		lastadd = ft_lstlast(*lst);
		lastadd->next = new;
	}
	else
		*lst = new;
}
