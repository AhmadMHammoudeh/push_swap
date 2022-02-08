/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2022/02/08 14:40:47 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_position(t_data *numb)
{
	int	i;

	i = 0;
	while (numb->list_b[i] == numb->num[i] && i < numb->input)
	{
		i++;
	}
	if (i < numb->input)
		return (0);
	ft_free(numb);
	exit(1);
}

int	ft_check_input(char *arg, t_data *numb)
{
	int	i;

	i = 0;
	if (arg[0] == '-' && !arg[1])
	{
		ft_free(numb);
		exit(write(2, "Error\n", 6));
	}
	while (arg[i] != '\0' && ((arg[i] >= 48 && arg[i] <= 57) \
	|| arg[i] == ' ' || arg[i] == '-'))
		i++;
	if (arg[i] != '\0')
	{
		ft_free(numb);
		exit (write(2, "Error\n", 6));
	}
	return (1);
}

void	ft_errors(t_data *numb, char **argc, int i)
{
	int	j;

	j = 0;
	while (argc[i])
	{
		ft_check_input(argc[i++], numb);
	}
	if (numb->flag_int == 1)
	{
		ft_free(numb);
		exit (write(2, "Error\n", 6));
	}
	i = -1;
	while (++i < numb->input)
	{
		j = -1;
		while (++j < i)
		{
			if (numb->list_b[i] == numb->list_b[j])
			{
				ft_free(numb);
				exit (write(2, "Error\n", 6));
			}
		}
	}
}

void	ft_initial(t_data *numb)
{
	numb->num = 0;
	numb->b = 0;
	numb->limita = 0;
	numb->push_b = 0;
	numb->flag_int = 0;
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
	check_position(&numb);
	ft_binary(&numb);
	ft_free(&numb);
	return (0);
}
