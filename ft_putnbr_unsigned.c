/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_unsigned.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/21 12:42:10 by ahhammou          #+#    #+#             */
/*   Updated: 2021/10/26 21:22:58 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_numlength_u(unsigned int n)
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

int	ft_putnbr_unsigned(unsigned int nb)
{
	int	i;

	i = ft_numlength_u(nb);
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(48 + nb % 10);
	return (i);
}
