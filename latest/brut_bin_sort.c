/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brut_bin_sort.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:46:55 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/31 14:35:51 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_brute_sort(int *num, int len)
{
	int	i;
	int	temp;

	temp = 0;
	i = 0;
	while (i < len)
	{
		if (num[i] > num[i + 1])
		{
			temp = num[i];
			num[i] = num [i + 1];
			num[i + 1] = temp;
		}
		i++;
	}
	return (num);
}

void	ft_binary_sort(t_data *numb, int j)
{
	int	i;
	int	k;

	i = 0;
	k = 0;
	while (k < numb->input)
	{
		if (check_position(numb))
			break ;
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

void	ft_final_check(t_data *numb)
{
	int	i;

	i = 0;
	while (i < numb->input)
	{
		if (check_position(numb))
			break ;
		if (numb->list_binary[i] != numb->num_bin[i])
			ft_rotate(numb);
		else
		{
			ft_push(numb);
			i++;
		}
	}
	while (--i > 0)
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
}

int	*ft_swapper(char **args, int argv, t_data *numb)
{
	int	i;
	int	j;
	int	*num;

	j = 0;
	num = malloc(sizeof(int *) * (count(args[1], ' ')));
	i = 0;
	ft_twolist(args, argv, numb);
	while (i < numb->input)
	{
		num[i] = numb->list_b[i];
		i++;
	}
	numb->num = num;
	while (j++ < i)
		numb->num = ft_brute_sort(numb->num, i - 1);
	ft_binary_list(numb);
	return (numb->num);
}
