/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 20:22:24 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Create a node with malloc, init variable "content" with content
** and the variable next with null
*/
t_list	*ft_lstnew(void *content)
{
	t_list	*i;

	i = malloc(sizeof(t_list));
	if (!i)
		return (NULL);
	i->content = content;
	i->next = NULL;
	return (i);
}
