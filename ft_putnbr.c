/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:42:10 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/26 21:15:34 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlength(long n)
{
	if (n > 999999999)
		return (10);
	if (n > 99999999)
		return (9);
	if (n > 9999999)
		return (8);
	if (n > 999999)
		return (7);
	if (n > 99999)
		return (6);
	if (n > 9999)
		return (5);
	if (n > 999)
		return (4);
	if (n > 99)
		return (3);
	if (n > 9)
		return (2);
	return (1);
}

static int	ft_length(int nb)
{
	int	i;

	if (nb < 0 && nb != -2147483648)
		i = (int)ft_numlength(-nb) + 1;
	else if (nb == -2147483648)
		i = 11;
	else
		i = (int)ft_numlength(nb);
	return (i);
}

int	ft_putnbr(int nb)
{
	int	i;

	i = ft_length(nb);
	if (nb == -2147483648)
	{
		ft_putnbr(nb / 10);
		ft_putchar('8');
	}
	else if (nb < 0)
	{
		ft_putchar('-');
		ft_putnbr(-nb);
	}
	else
	{
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
		}
		ft_putchar(48 + nb % 10);
	}
	return (i);
}
