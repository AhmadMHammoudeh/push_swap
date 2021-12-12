/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hex.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:42:10 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/29 13:50:04 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlength_h(unsigned long n)
{
	if (n > 281474976710656)
		return (13);
	if (n > 17592186044416)
		return (12);
	if (n > 1099511627776)
		return (11);
	if (n > 68719476736)
		return (10);
	if (n > 4294967296)
		return (9);
	if (n > 268435456)
		return (8);
	if (n > 16777216)
		return (7);
	if (n > 1048576)
		return (6);
	if (n > 65536)
		return (5);
	if (n > 4096)
		return (4);
	if (n > 255)
		return (3);
	if (n > 15)
		return (2);
	return (1);
}

static int	ft_numlength_l(unsigned long long n)
{
	if (n > 4503599627370496 * 256)
		return (16);
	if (n > 4503599627370496 * 16)
		return (15);
	if (n > 4503599627370496)
		return (14);
	return (0);
}

int	ft_putnbr_hexc(unsigned int nb)
{
	int	i;

	i = ft_numlength_h(nb);
	if (nb > 15)
	{
		ft_putnbr_hexc(nb / 16);
	}
	ft_putchar_hexc(48 + nb % 16);
	return (i);
}

int	ft_putnbr_hex(unsigned int nb)
{
	int	i;

	i = ft_numlength_h(nb);
	if (nb > 15)
	{
		ft_putnbr_hex(nb / 16);
	}
	ft_putchar_hex(48 + nb % 16);
	return (i);
}

int	ft_putnbr_p2(unsigned long long int nb)
{
	int					i;

	i = ft_numlength_l(nb);
	if (!i)
		i = ft_numlength_h(nb);
	i += 2;
	if (nb > 15)
	{
		ft_putnbr_p2(nb / 16);
	}
	ft_putchar_hex(48 + nb % 16);
	return (i);
}
