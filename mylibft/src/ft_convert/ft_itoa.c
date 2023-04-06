/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:11:26 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
** Using malloc, generate a string representing
** the integer value received as argument.
** Negative numbers have to be handled.
*/

static int	ft_abs(int n)
{
	if (n < 0)
		n = -n;
	return (n);
}

static size_t	ft_number_len(int n)
{
	size_t	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*res;
	size_t	pos;
	size_t	dig;

	dig = ft_number_len(n);
	res = ft_calloc(dig + 1, sizeof(char));
	if (!res)
		return (res);
	if (n < 0)
		res[0] = '-';
	else if (n == 0)
		res[0] = '0';
	pos = dig - 1;
	while (n)
	{
		res[pos] = ft_abs(n % 10) + '0';
		n = n / 10;
		pos--;
	}
	return (res);
}
