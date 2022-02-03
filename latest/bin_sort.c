/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2022/02/03 11:13:29 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position(t_data *numb)
{
	int	i;

	i = 0;
	while (numb->list_b[i] == numb->num[i] && i <= numb->input)
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

	i = 0;
	if (arg[0] == '-' && !arg[1])
		exit (write(2, "Error\n", 6));
	while (arg[i] != '\0' && ((arg[i] >= 48 && arg[i] <= 57) \
	|| arg[i] == ' ' || arg[i] == '-'))
		i++;
	if (arg[i] != '\0')
		exit (write(2, "Error\n", 6));
	return (1);
}

int	ft_errors(t_data *numb, char **argc, int i)
{
	int	j;

	j = 0;
	while (argc[i])
	{
		ft_check_input(argc[i]);
		i++;
	}
	if (numb->flag_int == 1)
		exit (write(2, "Error\n", 6));
	i = 0;
	while (i < numb->input)
	{
		j = 0;
		while (j < i)
		{
			if (numb->list_b[i] == numb->list_b[j])
				exit (write(2, "Error\n", 6));
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_initial(t_data *numb)
{
	numb->num = 0;
	numb->b = 0;
	numb->limita = 0;
	numb->push_b = 0;
	numb->flag_int = 0;
}

void	ft_free(t_data *numb)
{
	if (numb->num)
		free(numb->num);
	if (numb->list_b)
		free(numb->list_b);
	if (numb->list_binary)
		free(numb->list_binary);
}

int	main(int argv, char **argc)
{
	int		i;
	t_data	numb;

	i = 1;
	ft_initial(&numb);
	if (argv < 2)
		return (0);
	ft_swapper(argc, argv, &numb);
	ft_errors(&numb, argc, i);
	ft_binary(&numb);
	return (0);
}
