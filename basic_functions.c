/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basic_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:36:47 by ahhammou          #+#    #+#             */
/*   Updated: 2022/02/03 10:19:22 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap(t_data *numb, int i)
{
	int	c;

	c = numb->list_b[i];
	numb->list_b[i] = numb->list_b[i + 1];
	numb->list_b[i + 1] = c;
	printf("sa\n");
}

void	ft_push(t_data *numb)
{
	printf("pb\n");
	numb->b++;
	numb->limita++;
	numb->push_b++;
}

int	*ft_rotate(t_data *numb)
{
	int	i;
	int	temp;

	i = numb->limita;
	temp = numb->list_binary[i];
	while (i + 1 < numb->input)
	{
		numb->list_binary[i] = numb->list_binary[i + 1];
		i++;
	}
	numb->list_binary[i] = temp;
	i = numb->limita;
	temp = numb->list_b[i];
	while (i + 1 < numb->input)
	{
		numb->list_b[i] = numb->list_b[i + 1];
		i++;
	}
	numb->list_b[i] = temp;
	printf("ra\n");
	return (numb->list_a);
}

void	ft_rotate_r(t_data *numb)
{
	int	i;
	int	temp;

	temp = numb->list_b[numb->input - 1];
	i = numb->input - 1;
	while (i > numb->limita)
	{
		numb->list_b[i] = numb->list_b[i - 1];
		i--;
	}
	numb->list_b[numb->limita] = temp;
	printf("rra\n");
}

void	ft_push_a(t_data *numb)
{
	printf("pa\n");
	numb->push_b--;
	numb->b--;
	numb->limita--;
}
