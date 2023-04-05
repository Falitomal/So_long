/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 15:02:56 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** The funtion ft_strnstr searches for the first occurrence of the substring
** light in the string big,up to a maximum of len characters.
** It starts by checking if light is an empty string and if so,returns a pointer
** to big. Otherwise, it uses two nested loops to compare each character of light
** with the corresponding character of big, stopping if it finds a mismatch or
** if it reaches the end of either string  or if it exceeds the len limit.
** If it finds a match, it returns a pointer to the start of the match in big.
** If no match is found, it returns NULL.
*/

char	*ft_strnstr(const char *big, const char *light, size_t len)
{
	size_t	i;
	size_t	j;

	if (!*light)
		return ((char *)big);
	i = 0;
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == light[j] && (i + j) < len)
		{
			if (!light[j + 1])
				return ((char *)big + i);
			j++;
		}
		i++;
	}
	return (NULL);
}
