/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:14:00 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/30 15:21:13 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <stdarg.h>

int		ft_printf(const char *args, ...);
int		ft_putchar(char c);
int		ft_putnbr(int nb);
int		ft_putstr(char *str);
int		ft_strlen(const char *s);
int		ft_isalpha(int c);
int		ft_putnbr_unsigned(unsigned int nb);
int		ft_putnbr_hex(unsigned int nb);
int		ft_putnbr_hexc(unsigned int nb);
int		ft_putnbr_pre_p(unsigned long int nb);
int		ft_putnbr_pre_p1(long long nb);
int		ft_putnbr_p2(unsigned long long int nb);
int		ft_printf_sc(va_list ap, const char *args, int i, int j);
int		ft_printf_di(va_list ap, const char *args, int i, int j);
int		ft_printf_pu(va_list ap, const char *args, int i, int j);
int		ft_printf_x(va_list ap, const char *args, int i, int j);
int		ft_putchar_hex(char c);
int		ft_putchar_hexc(char c);
int		ft_putchar_p(char c, int i);

#endif
