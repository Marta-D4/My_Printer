/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 12:08:50 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/07 11:53:30 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr(int nb)
{
	int		count;
	char	x;

	count = 0;
	if (nb == -2147483648)
	{
		count += write(1, "-2147483648", 11);
		return (count);
	}
	if (nb < 0)
	{
		count += write(1, "-", 1);
		count += ft_putnbr(-nb);
	}
	else if (nb > 9)
	{
		count += ft_putnbr(nb / 10);
		count += ft_putnbr(nb % 10);
	}
	else
	{
		x = nb + '0';
		count += write(1, &x, 1);
	}
	return (count);
}

int	ft_putunsnbr(unsigned int nb)
{
	int		count;
	char	x;

	count = 0;
	if (nb > 9)
	{
		count += ft_putunsnbr(nb / 10);
		count += ft_putunsnbr(nb % 10);
	}
	else
	{
		x = nb + '0';
		count += write(1, &x, 1);
	}
	return (count);
}

int	ft_puthex(unsigned long long nb, char *hex)
{
	int	count;

	count = 0;
	if (nb < 16)
		count += write(1, &hex[nb], 1);
	else
	{
		count += ft_puthex(nb, hex);
		count += write(1, &hex[nb % 16], 1);
	}
	return (count);
}

int	ft_putptr(void *ptr)
{
	int	count;

	count = 0;
	if (!ptr)
	{
		count += write(1, "(nil)", 5);
		return (count);
	}
	count += write(1, "0x", 2);
	count += ft_puthex((unsigned long long)ptr, "0123456789abcdef");
	return (count);
}
