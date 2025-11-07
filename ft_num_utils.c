/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:08:50 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/07 10:53:49 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libprintf.h"

int	ft_putnbr(va_list args)
{
	int	nb;
	int	count;

	nb = va_arg(args, int);
	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, '-', 1);
		count += ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
		count += write(1, nb + '0', 1);
	return (count);
}

int	ft_putunsnbr(va_list args)
{
	unsigned int	nb;
	int				count;

	nb = va_arg(args, unsigned int);
	count = 0;
	if (nb > 9)
	{
		count += ft_putunsnbr(nb / 10);
		count += ft_putunsnbr(nb % 10);
	}
	else
		count += write(1, nb + '0', 1);
	return (count);
}

int	ft_puthex(va_list args, char *hex)
{
	unsigned long long	nb;
	int					count;

	nb = va_arg(args, unsigned long long);
	count = 0;
	if (nb < 16)
		count += write(1, &hex[nb], 1);
	else
	{
		count += ft_puthex(args, hex);
		count += write(1, &hex[nb % 16], 1);
	}
	return (count);
}

int	ft_putptr(va_list args)
{
	unsigned long long	ptr;
	int					count;

	ptr = va_arg(args, unsigned long long);
	count = 0;
	count += write(1, "0x", 2);
	count += ft_puthex(ptr, "0123456789abcdef");
	return (count);
}
