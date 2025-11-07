/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:35:50 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/07 11:50:50 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
int			ft_putchar(va_list args, int count);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_str(va_list args, int count);
int			ft_putnbr(int nb);
int			ft_putunsnbr(unsigned int nb);
int			ft_puthex(unsigned long long nb, char *hex);
int			ft_putptr(void *ptr);

#endif