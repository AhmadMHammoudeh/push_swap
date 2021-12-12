/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 14:53:24 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/29 14:28:20 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putchar_hexc(char c)
{
	if (c > 47 && c < 58)
		write(1, &c, 1);
	if (c > 57 && c < 64)
	{
		c = c + 7;
		write(1, &c, 1);
	}
	return (1);
}

int	ft_putchar_hex(char c)
{
	if (c > 47 && c < 58)
		write(1, &c, 1);
	if (c > 57 && c < 64)
	{
		c = c + 39;
		write(1, &c, 1);
	}
	return (1);
}

int	ft_putnbr_pre_p(unsigned long int nb)
{
	int	i;

	if (nb == 0)
	{
		write(1, "(nil)", 5);
		return (1);
	}
	write(1, "0x", 2);
	i = ft_putnbr_p2(nb);
	return (i);
}

int	ft_putnbr_pre_p1(long long nb)
{
	int	i;

	write(1, "0x", 2);
	i = ft_putnbr_p2(nb);
	return (i);
}
