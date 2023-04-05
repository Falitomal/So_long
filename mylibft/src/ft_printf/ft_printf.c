/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jledesma <jledesma@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 19:01:54 by jledesma          #+#    #+#             */
/*   Updated: 2023/03/27 17:43:08 by jledesma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_all(const char *str, int *i, va_list args, int j)
{
	if (str[j + 1] == '%')
		ft_putchar_i('%', i);
	else if (str[j + 1] == 'c')
		ft_putchar_i(va_arg(args, int), i);
	else if (str[j + 1] == 's')
		ft_putstr_i(va_arg(args, char *), i);
	else if (str[j + 1] == 'p')
	{
		ft_putstr_i("0x", i);
		ft_puthex(va_arg(args, unsigned long long), i, "0123456789abcdef");
	}
	else if (str[j + 1] == 'd' || str[j + 1] == 'i')
		ft_putint(va_arg(args, int), i);
	else if (str[j + 1] == 'u')
		ft_putint(va_arg(args, unsigned int), i);
	else if (str[j + 1] == 'x')
		ft_puthex(va_arg(args, unsigned int), i, "0123456789abcdef");
	else if (str[j + 1] == 'X')
		ft_puthex(va_arg(args, unsigned int), i, "0123456789ABCDEF");
}

int	ft_printf(char const *str, ...)
{
	va_list	args;
	int		i;
	int		j;

	i = 0;
	j = 0;
	va_start(args, str);
	while (str[j])
	{
		if (str[j] == '%')
		{
			ft_print_all(str, &i, args, j);
			j++;
		}
		else
			ft_putchar_i(str[j], &i);
		j++;
	}
	va_end(args);
	return (i);
}
