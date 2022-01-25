/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/25 08:13:35 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position(t_data *numb)
{
	int	i;

	i = 0;
	while (numb->list_b[i] == numb->num[i] && i <= numb->length)
	{
		i++;
	}
	if (numb->list_b[i] != numb->num[i])
		return (0);
	return (1);
}

int	ft_check_input(char *arg)
{
	int	i;
	int	j;

	i = 0;
	while (arg[i] != '\0' && (arg[i] >= 48 && arg[i] <= 57))
		i++;
	if (arg[i] == '-')
	{
		while (arg[++i])
		{
			if (arg[i] != '\0' && (arg[i] >= 48 && arg[i] <= 57))
				j = 0;
			else
				break ;
		}
	}
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	ft_errors(t_data *numb, char **argc, int i)
{
	int	j;

	while (argc[i])
	{
		j = ft_check_input(argc[i]);
		if (j != 1)
			return (write(1, "Error\n", 6));
		i++;
	}
	if (numb->flag_int == 1)
		return (write(1, "Error\n", 6));
	i = 0;
	while (i < numb->length)
	{
		j = 0;
		while (j < i)
		{
			if (numb->num[i] == numb->num[j])
				return (write(1, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_initial(t_data *numb)
{
	numb->num = NULL;
	numb->b = 0;
	numb->limita = 0;
	numb->push_b = 0;
}

int	main(int argv, char **argc)
{
	int		i;
	t_data	numb;

	i = 1;
	ft_initial(&numb);
	numb.num = ft_swapper(argc, argv, &numb);
	if (ft_errors(&numb, argc, i))
		return (-1);
	ft_binary(&numb);
	return (0);
}
