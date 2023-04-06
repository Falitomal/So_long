/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 10:46:54 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** The function first calculates the length of the destination string (dst_len)
** and the length of the source string (src_len).
** It then checks if the size of the destination buffer (size)
** is greater than or equal to dst_len or is 0. If size is smaller than dst_len,
** then the function returns the length of the source string plus the size of 
** the destination buffer.
*/

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	dst_len = ft_strlen(dest);
	src_len = ft_strlen(src);
	if (size <= dst_len || size == 0)
		return (src_len + size);
	while (src[i] && dst_len + i < size - 1)
	{
		dest[dst_len + i] = src[i];
		i++;
	}
	dest[dst_len + i] = '\0';
	return (dst_len + src_len);
}
