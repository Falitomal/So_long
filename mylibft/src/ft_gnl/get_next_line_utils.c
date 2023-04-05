/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/27 11:30:13 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_protected(const char *s)
{
	size_t	i;

	if (!s)
		return (0);
	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_substr_sizeprotected(char const *s, unsigned int start, size_t len)
{
	char	*substr;
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen_protected(s);
	if (start > s_len)
	{
		substr = ft_calloc(1, sizeof(char));
		if (!substr)
			return (0);
		return (substr);
	}
	if (s_len - start < len)
		len = s_len;
	substr = ft_calloc(len + 1, sizeof(char));
	if (!substr)
		return (0);
	i = 0;
	while (i < len && s[i + start])
	{
		substr[i] = s[i + start];
		i++;
	}
	return (substr);
}

char	*ft_strjoin_sizeprotected(char const *s1, char const *s2)
{
	char	*str;
	size_t	s1_len;
	size_t	s2_len;
	size_t	i;

	s1_len = ft_strlen_protected(s1);
	s2_len = ft_strlen_protected(s2);
	str = ft_calloc(s1_len + s2_len + 1, sizeof(char));
	if (!str)
		return (0);
	i = 0;
	while (i < s1_len)
	{
		str[i] = s1[i];
		i++;
	}
	i = 0;
	while (i < s2_len)
	{
		str[i + s1_len] = s2[i];
		i++;
	}
	return (str);
}
