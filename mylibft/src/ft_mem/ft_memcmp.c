/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 21:07:41 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Compares the first num bytes of the block of memory pointed
** by ptr1 to the first num bytes pointed by ptr2,
** returning zero if they all match or a value different from
** zero representing which is greater if they do not.
*/

int	ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	size_t				i;
	unsigned char		*dest;
	unsigned const char	*sour;

	if (num == 0)
		return (0);
	dest = (unsigned char *)ptr1;
	sour = (unsigned char *)ptr2;
	i = 0;
	while (i < num - 1 && dest[i] == sour[i])
		i++;
	return (dest[i] - sour[i]);
}
