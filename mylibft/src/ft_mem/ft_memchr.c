/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:29:25 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** This function locates the first occurrence of character
** in string converted to a unsigned char.
** Returns a pointer to the byte located, or null if no exists.
*/

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;
	unsigned char	chter;

	str = (unsigned char *)s;
	chter = (unsigned char)c;
	i = 0;
	while (i < n)
	{
		if (str[i] == chter)
			return ((void *)str + i);
		i++;
	}
	return (NULL);
}
