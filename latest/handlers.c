/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handlers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:44:40 by ahhammou          #+#    #+#             */
/*   Updated: 2022/02/03 11:12:51 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(char *s, t_data *numb)
{
	int				i;
	unsigned long	num;
	int				sign;

	i = 0;
	num = 0;
	sign = 1;
	if (s[0] == '-')
	{
		if (!s[++i])
			exit (write(2, "Error\n", 6));
		sign = -sign;
	}	
	while (s[i] != '\0')
	{
		if (s[i] == '-')
			exit (write(2, "Error\n", 6));
		num = num * 10 + s[i++] - 48;
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
	numb->input = 0;
	if (argv < 3)
	{
		numb->list_a = malloc(sizeof(int *) * (count(args[1], ' ')));
		numb->list_b = malloc(sizeof(int *) * (count(args[1], ' ')));
		numb->list_binary = malloc(sizeof(int *) * (count(args[1], ' ')));
		ft_split(args[numb->input + 1], ' ', numb);
	}
	else
	{
		numb->list_a = malloc(sizeof(int) * (argv));
		numb->list_b = malloc(sizeof(int) * (argv));
		numb->list_binary = malloc(sizeof(int) * (argv));
		while (numb->input + 1 < argv)
		{
			numb->list_a[numb->input] = ft_atoi(args[numb->input + 1], numb);
			numb->list_b[numb->input] = numb->list_a[numb->input];
			numb->input++;
		}
		if (numb->list_a)
			free(numb->list_a);
	}
}

int	ft_bin_length(t_data *numb)
{
	if (numb->input <= 2)
		return (1);
	if (numb->input <= 4)
		return (2);
	if (numb->input <= 8)
		return (3);
	if (numb->input <= 16)
		return (4);
	if (numb->input <= 32)
		return (5);
	if (numb->input <= 64)
		return (6);
	if (numb->input <= 128)
		return (7);
	if (numb->input <= 256)
		return (8);
	if (numb->input <= 512)
		return (9);
	if (numb->input <= 1024)
		return (10);
	if (numb->input <= 2048)
		return (11);
	return (12);
}

void	ft_binary_list(t_data *numb)
{
	int	i;
	int	j;

	i = 0;
	while (i < numb->input)
	{
		j = 0;
		while (numb->num[j] != numb->list_b[i])
			j++;
		numb->list_binary[i] = j;
		i++;
	}
}
