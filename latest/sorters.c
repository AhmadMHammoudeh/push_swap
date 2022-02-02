/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorters.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:43:52 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/31 19:03:41 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sorter_three(t_data *numb, int i)
{
	int	j;

	while (i < numb->input)
	{
		j = 0;
		while (numb->list_b[i] != numb->num[j])
			j++;
		if (i == j)
			i++;
		else if (j - i == 1)
			ft_swap(numb, i);
		else if (j - i == 2)
			ft_rotate(numb);
	}
}

void	ft_sort_three(t_data *numb)
{
	int	i;

	i = 0;
	if (numb->list_b[0] == numb->num[1] && \
		numb->list_b[1] == numb->num[2])
	{
		ft_rotate_r(numb);
		return ;
	}
	else if (numb->list_b[0] == numb->num[0] && \
			numb->list_b[1] == numb->num[2])
	{
		ft_swap(numb, 0);
		ft_rotate(numb);
		return ;
	}
	ft_sorter_three(numb, i);
}

void	ft_sortest_five(t_data *numb)
{
	ft_push_a(numb);
	ft_push_a(numb);
	if (numb->list_b[0] > numb->list_b[1])
		ft_swap(numb, 0);
	ft_rotate_r(numb);
}

void	ft_sorter_five(t_data *numb)
{
	int	i;

	i = 2;
	while (i < numb->input)
	{
		if (numb->list_b[3] == numb->num[0])
		{
			ft_rotate_r(numb);
			if (numb->list_b[2] == numb->num[3] \
			&& numb->list_b[3] == numb->num[4] \
			&& numb->list_b[4] == numb->num[0])
				break ;
		}
		else if (numb->list_b[2] == numb->num[3] \
		&& numb->list_b[3] == numb->num[4] \
		&& numb->list_b[4] == numb->num[0])
			break ;
		else if (numb->list_b[2] > numb->list_b[3])
			ft_swap(numb, 2);
		else
			ft_rotate(numb);
		i++;
	}
}

void	ft_sort_five(t_data *numb)
{
	int	i;

	i = 0;
	if (check_position(numb))
		return ;
	while (i < 2)
	{
		if (numb->list_b[i] != numb->num[0] && numb->list_b[i] != numb->num[3] \
			&& numb->list_b[i] != numb->num[4])
		{
			ft_push(numb);
			i++;
		}
		else
			ft_rotate(numb);
	}
	ft_sorter_five(numb);
	ft_sortest_five(numb);
}
