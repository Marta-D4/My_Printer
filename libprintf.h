/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libprintf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madiaz-e <madiaz-e@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 13:35:50 by madiaz-e          #+#    #+#             */
/*   Updated: 2025/11/05 12:26:15 by madiaz-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBPRINTF_H
# define LIBPRINTF_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>

int			ft_printf(const char *str, ...);
static int	ft_convert(const char *str, va_list args);
int			ft_putchar(va_list args, int count);
size_t		ft_strlen(const char *s);
void		ft_putstr_fd(char *s, int fd);
int			ft_str(va_list args, int count);
int			ft_putnbr(va_list args);

#endif