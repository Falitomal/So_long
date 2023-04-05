/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 19:43:13 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 15:44:16 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* 
** Function ft_isspace removes spaces, line breaks,
** tabs etc., various ascii characters
*/
static int	ft_isspace(char c)
{
	if ((c >= 9 && c <= 13) || c == 32)
		return (1);
	return (0);
}

/* 
** Function ft_overflow determines that the number
** does not overflow by a maximum number.
** checks for negative or positive maxima
*/

int	ft_overflow(int res, int sign)
{
	if (res > 0 && sign < 0)
		return (0);
	if (res < 0 && sign > 0)
		return (-1);
	return (res);
}
/* 
** Function ft_atoi replicates the original function with the same treatment
** of signs and using the removal of special characters with ft_isspace.
*/

int	ft_atoi(const char *str)
{
	int		sign;
	int		i;
	int		res;

	i = 0;
	res = 0;
	sign = 1;
	while (ft_isspace(str[i]))
		i++;
	if (!str)
		return (0);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = ((res * 10) + (str[i] - '0'));
		i++;
	}
	res *= sign;
	return (ft_overflow(res, sign));
}
