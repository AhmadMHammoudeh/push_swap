/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 11:13:04 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/23 15:21:08 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check(va_list ap, const char *args, int i, int j)
{
	if (args[i + 1] == 's' || args[i + 1] == 'c')
		j = ft_printf_sc(ap, args, ++i, j);
	else if (args[i + 1] == '%')
		j += ft_putchar_p('%', ++i);
	else if ((args[i + 1] == 'd' || args[i + 1] == 'i'))
		j = ft_printf_di(ap, args, ++i, j);
	else if (args[i + 1] == 'X' || args[i + 1] == 'x')
		j = ft_printf_x(ap, args, ++i, j);
	else if (args[i + 1] == 'p' || args[i + 1] == 'u')
		j = ft_printf_pu(ap, args, ++i, j);
	else
		return (0);
	return (j);
}

int	ft_printf(const char *args, ...)
{
	va_list			ap;
	int				i;
	int				j;

	i = 0;
	j = 0;
	va_start(ap, args);
	while (args[i])
	{
		if (args[i] == '%')
		{
			j = check(ap, args, i++, j);
		}
		else
			j += ft_putchar(args[i]);
		i++;
	}
	va_end(ap);
	return (j);
}
