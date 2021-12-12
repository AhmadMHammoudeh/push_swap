/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2021/11/23 18:44:54 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"


void ft_swap(int a, int b, int d)
{
	int c;
	
	c = a;
	a = b;
	b = c;
}
int ft_atoi(char *s)
{
	int i;
	int num;

	i = 0;
	num = 0;
	while (s[i])
	{
		num *= 10;  
		num = s[i] - 48 + num;
		// printf("%d", num);
		i++;
	}
	return (num);
}

int ft_brute_sort(int *num, int len)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i <= len)
	{
		if (num[i+1] == '\0')
		{
			printf("%d", num[i]);
			break ;
		}
		else if (num[i] > num[i + 1])
		{
			temp = num[i];
			num[i] = num [i + 1];
			num[i + 1] = temp;
		}
		printf("%d", num[i]);
		i++;
	}
}

int ft_swapper(char **args, int argv)
{
	int i;
	int *num;

	num = malloc(sizeof(int*) * argv);
	i = 1;
	while (args[i])
	{
		num[i - 1] = ft_atoi(args[i]);
		// printf("%d", num[i - 1]);
		i++;
	}
	num[i - 1] = '\0';
	ft_brute_sort(num, i - 1);
	return (0);
}


int ft_check_input(char *arg)
{
	int i;

	i = 0;
	while (arg[i] != '\0' && (arg[i] >= 48 && arg[i] <= 57))
	{
		i++;
	}
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	main(int argv, char **argc)
{
	int i;
	int j;

	i = 1;
	if(argv < 2)
		return (printf("Error, Not Enough Arguments\n"));
	while (argc[i])
	{
		j = ft_check_input(argc[i]);
		if (j != 1)
			return (printf("Error, Arguments Invalid\n"));
		i++;
	}
	return (ft_swapper(argc, argv));
}