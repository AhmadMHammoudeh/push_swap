/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2021/12/13 20:42:13 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "ft_strlen.c"

typedef struct s_data {
	int *num;
	int limit;
	int *list_a;
	int *list_b;
	int length;
	int b;
} t_data;

void ft_swap(t_data *numb, int i, int j)
{
	int c;

	c = numb->list_a[i];
	numb->list_a[i] = numb->list_a[j];
	numb->list_a[j] = c;
}

void ft_push(t_data *numb, int i)
{
	if (!numb->b)
		numb->b = 0;
	while(numb->b < i)
	{
		numb->list_b[numb->b] = numb->list_a[i - numb->b];
		numb->b++;
	}
	printf("pa\n");
}

void ft_rotate(t_data *numb)
{
	int i;
	int temp;

	i = 0;
	temp = numb->list_a[0];
	while (numb->list_a[i])
	{
		if (!numb->list_a[i + 1])
		{
			numb->list_a[i] = temp;
			break;
		}
		numb->list_a[i] = numb->list_a[i + 1];
		i++;
	}
}

void ft_rotate_r(t_data *numb)
{
	int i;
	int temp;

	i = 1;
	temp = numb->num[ft_numlen(numb->num) - 1];
	i = ft_numlen(numb->num) - 1;
	while (i > 0)
	{
		numb->num[i] = numb->num[i - 1];
		i--;
	}
	numb->num[0] = temp;
}

int ft_atoi(char *s)
{
	int i;
	int num;
	int sign;

	i = 0;
	num = 0;
	sign = 1;
	if (s[i] == '-')
	{
		sign = -sign;
		i++;
	}
	while (s[i])
	{
		num *= 10;
		num = s[i] - 48 + num;
		i++;
	}
	return (num * sign);
}

int *ft_brute_sort(int *num, int len)
{
	int i;
	int temp;

	temp = 0;
	i = 0;
	while (i <= len)
	{
		if (num[i+1] == '\0')
			break ;
		else if (num[i] > num[i + 1])
		{
			temp = num[i];
			num[i] = num [i + 1];
			num[i + 1] = temp;
		}
		i++;
	}
	return (num);
}

void ft_twolist(char **args, int argv, t_data *numb)
{
	int i;

	i = 0;
	numb->list_a = malloc(sizeof(int *) * argv);
	numb->list_b = malloc(sizeof(int*) * argv);
	while (args[i])
	{
		numb->list_a[i - 1] = ft_atoi(args[i]);
		i++;
	}
	numb->list_a[i - 1] = '\0';
}

void ft_sort(t_data *numb, int i, int j)
{
	int a;
	int b;

	a = 0;
	b = 0;
	if (j - i == 1)
		ft_swap(numb, i, j);
	else
		ft_rotate(numb);
}

void ft_solver(t_data *numb)
{
	int i;
	int j;

	i = 0;
	numb->length = ft_numlen(numb->num);
	while (numb->list_a[i])
	{
		j = 0;
		while (numb->num[j] != numb->list_a[i])
			j++;
		if (j != i)
		{
			ft_push(numb, i);
			ft_sort(numb, i, j);
		}
		else
			i++;
	}
}

int *ft_swapper(char **args, int argv, t_data *numb)
{
	int i;
	int *num;
	
	if (!num)
	{
		num = malloc(sizeof(int*) * argv);
		i = 1;
		while (args[i])
		{
			num[i - 1] = ft_atoi(args[i]);
			i++;
		}
		num[i - 1] = '\0';
	}
	numb->num = num;
	while (numb->num[i])
		printf("%d", numb->num[i++]);
	numb->num = ft_brute_sort(numb->num, i - 1);
	ft_twolist(args, argv, numb);
	ft_solver(numb);
	return (numb->num);
}

int ft_check_input(char *arg)
{
	int i;
	int j;

	i = 0;
	while (arg[i] != '\0' && (arg[i] >= 48 && arg[i] <= 57))
		i++;
	if (arg[i] == '-')
	{
		while(arg[++i])
		{
			if (arg[i] != '\0' && (arg[i] >= 48 && arg[i] <= 57))
				j = 0;
			else
				break;
		}
	}
	if (arg[i] != '\0')
		return (0);
	return (1);
}

int	main(int argv, char **argc)
{
	int i;
	int j;
	t_data numb;

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
	i = 0;
	while (argc[i])
	{
		numb.num = ft_swapper(argc, argv, &numb);
		i++;
	}
	i = 0;
	j = 0;
	while (numb.num[i])
	{
		while(j < i)
		{
			if (numb.num[i] == numb.num[j])
				return (printf("Error, Duplicate Entry\n"));
			j++;
		}
		i++;
	}
	i = 0;
	while (numb.num[i])
	{
		// printf("Correct:%d My Answer: %d \n", numb.num[i], numb.list_a[i]);
		i++;
	}
	return (0);
}
