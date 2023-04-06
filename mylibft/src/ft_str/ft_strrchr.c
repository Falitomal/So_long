/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 20:56:56 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** searches for the last occurrence of the character c (an unsigned char)
** in the string pointed to, by the argument str
*/

char	*ft_strrchr(const char *str, int c)
{
	size_t	len;
	char	*s;

	len = ft_strlen(str);
	s = (char *)(str + len);
	while (s >= str)
	{
		if (*s == (char)c)
			return (s);
		s--;
	}
	return (NULL);
}
