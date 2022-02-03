/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_bin_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:46:55 by ahhammou          #+#    #+#             */
/*   Updated: 2022/02/03 11:12:14 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_brute_sort(t_data *numb, int len)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < len)
	{
		if (numb->num[i] > numb->num[i + 1])
		{
			temp = numb->num[i];
			numb->num[i] = numb->num [i + 1];
			numb->num[i + 1] = temp;
		}
		i++;
	}
}

void	ft_binary_sort(t_data *numb, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < numb->input)
	{
		if (((numb->list_binary[i] >> j) & 1) == 1)
			ft_rotate(numb);
		else
		{
			ft_push(numb);
			i++;
		}
		k++;
	}
	while (numb->limita > 0)
		ft_push_a(numb);
}

void	ft_binary(t_data *numb)
{
	int	bits;
	int	i;
	int	j;
	int	exp;

	i = 0;
	if (numb->input == 3)
		ft_sort_three(numb);
	else if (numb->input == 5)
		ft_sort_five(numb);
	else
	{
		bits = ft_bin_length(numb);
		while (i < bits)
		{
			exp = 1;
			j = i + 1;
			while (--j != 0)
				exp *= 10;
			ft_binary_sort(numb, i);
			i++;
		}
	}
	ft_free(numb);
}

void	ft_swapper(char **args, int argv, t_data *numb)
{
	int	i;
	int	j;

	j = 0;
	numb->num = malloc(sizeof(int) * (argv));
	i = 0;
	ft_twolist(args, argv, numb);
	while (i < numb->input)
	{
		numb->num[i] = numb->list_b[i];
		i++;
	}
	while (j++ < i)
		ft_brute_sort(numb, i - 1);
	ft_binary_list(numb);
}
