/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_sc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/29 12:36:03 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/30 01:55:19 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf_sc(va_list ap, const char *args, int i, int j)
{
	char			c;
	char			*s;

	if (args[i] == 's')
	{
		s = va_arg(ap, char *);
		j += ft_putstr(s);
		i++;
	}
	else if (args[i] == 'c')
	{
		c = va_arg(ap, int);
		j += ft_putchar(c);
		i++;
	}
	return (j);
}

int	ft_printf_x(va_list ap, const char *args, int i, int j)
{
	unsigned long long int	n;

	if (args[i] == 'X')
	{
		n = va_arg(ap, unsigned int);
		j += ft_putnbr_hexc(n);
		i++;
	}
	else if (args[i] == 'x')
	{
		n = va_arg(ap, unsigned int);
		j += ft_putnbr_hex(n);
		i++;
	}
	return (j);
}

int	ft_printf_pu(va_list ap, const char *args, int i, int j)
{
	unsigned long long int	n;

	if (args[i] == 'p')
	{
		n = va_arg(ap, unsigned long long);
		j += ft_putnbr_pre_p1(n);
		i++;
	}
	else if (args[i] == 'u')
	{
		n = va_arg(ap, unsigned int);
		j += ft_putnbr_unsigned(n);
		i++;
	}
	return (j);
}

int	ft_printf_di(va_list ap, const char *args, int i, int j)
{
	unsigned long long int	n;

	if (args[i] == 'd' || args[i] == 'i')
	{
		n = va_arg(ap, int);
		j += ft_putnbr(n);
		i++;
	}
	return (j);
}

int	ft_putchar_p(char c, int i)
{
	i = 1;
	write(1, &c, 1);
	return (i);
}
