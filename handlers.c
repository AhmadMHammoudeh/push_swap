/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:44:40 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/25 02:54:45 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s, t_data *numb)
{
	int				i;
	unsigned long	num;
	int				sign;

	numb->flag_int = 0;
	i = 0;
	num = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -sign;
		i++;
	}
	if (s[0] == '0')
		return (0);
	while (s[i])
	{
		num *= 10;
		num = s[i++] - 48 + num;
	}
	if (num > 2147483648 && sign == -1)
		numb->flag_int = 1;
	if (num > 2147483647 && sign == 1)
		numb->flag_int = 1;
	return ((int)num * sign);
}

int	ft_bin(int n)
{
	int	i;
	int	j;
	int	num;
	int	exp;

	i = 0;
	num = 0;
	while (n > 1)
	{
		exp = 1;
		j = i + 1;
		while (--j != 0)
			exp *= 10;
		num = (n % 2) * exp + num;
		n /= 2;
		i++;
	}
	if (i > 0)
		num = (n % 2) * exp * 10 + num;
	else
		num = (n % 2) + num;
	return (num);
}

void	ft_twolist(char **args, int argv, t_data *numb)
{
	int	i;

	i = 1;
	numb->list_a = malloc(sizeof(int *) * argv);
	numb->list_b = malloc(sizeof(int *) * argv);
	numb->list_binary = malloc(sizeof(int *) * argv);
	while (i < argv)
	{
		numb->list_a[i - 1] = ft_atoi(args[i], numb);
		numb->list_b[i - 1] = numb->list_a[i - 1];
		i++;
	}
}

int	ft_bin_length(t_data *numb)
{
	if (numb->length <= 2)
		return (1);
	if (numb->length <= 4)
		return (2);
	if (numb->length <= 8)
		return (3);
	if (numb->length <= 16)
		return (4);
	if (numb->length <= 32)
		return (5);
	if (numb->length <= 64)
		return (6);
	if (numb->length <= 128)
		return (7);
	if (numb->length <= 256)
		return (8);
	if (numb->length <= 512)
		return (9);
	if (numb->length <= 1024)
		return (10);
	if (numb->length <= 2048)
		return (11);
	return (12);
}

void	ft_binary_list(t_data *numb)
{
	int	i;
	int	j;

	numb->list_a_bin = malloc(sizeof(int *) * numb->length);
	numb->num_bin = malloc(sizeof(int *) * numb->length);
	i = 0;
	while (i < numb->length)
	{
		j = 0;
		while (numb->num[j] != numb->list_a[i])
			j++;
		numb->list_a_bin[i] = ft_bin(j);
		numb->list_binary[i] = j;
		numb->num_bin[i] = ft_bin(i);
		i++;
	}
}
