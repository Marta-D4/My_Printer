/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:36:35 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/07 11:48:05 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_convert(const char str, va_list args)
{
	int	count;

	count = 0;
	if (str == '%')
		count += write(1, "%", 1);
	else if (str == 'c')
		count += ft_putchar(args, count);
	else if (str == 's')
		count += ft_str(args, count);
	else if (str == 'i' || str == 'd')
		count += ft_putnbr(va_arg(args, int));
	else if (str == 'u')
		count += ft_putunsnbr(va_arg(args, unsigned int));
	else if (str == 'x')
		count += ft_puthex(va_arg(args, unsigned int),
				"0123456789abcdef");
	else if (str == 'X')
		count += ft_puthex(va_arg(args, unsigned int),
				"0123456789ABCDEF");
	else if (str == 'p')
		count += ft_putptr(va_arg(args, void *));
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		i;
	int		count;

	if (!str)
		return (-1);
	i = 0;
	count = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] != '%')
			count += write(1, &str[i], 1);
		else
		{
			count += ft_convert(str[i + 1], args);
			i++;
		}
		i++;
	}
	va_end(args);
	return (count);
}
