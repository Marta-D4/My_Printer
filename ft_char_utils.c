/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_char_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 13:08:44 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/07 11:43:55 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

//CONVERSIÓN %c
//Solo añadimos 1 a count pq solo escribe un caracter
int	ft_putchar(va_list args, int count)
{
	char	c;

	c = va_arg(args, int);
	count += write(1, &c, 1);
	return (count);
}

size_t	ft_strlen(const char *s) //Longitud de una cadena
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

void	ft_putstr_fd(char *s, int fd) //Escritura de una cadena
{
	int	i;

	i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

//CONVERSIÓN %s
//Si la cadena está vacia devolvemos (null), si no mandamos la
//cadena por el terminal y devolvemos su longitud.
int	ft_str(va_list args, int count)
{
	char	*str;

	str = va_arg(args, char *);
	if (!str)
	{
		write(1, "(null)", 6);
		return (count + 6);
	}
	ft_putstr_fd(str, 1);
	count += ft_strlen(str);
	return (count);
}
