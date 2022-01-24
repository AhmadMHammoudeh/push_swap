/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bin_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/22 07:49:50 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "ft_strlen.c"

typedef struct s_data {
	int *num;
	int *num_bin;
	int limita;
	int limitb;
	int *list_a;
	int *list_a_bin;
	int *list_b;
	int *list_binary;
	int length;
	int b;
	int j;
	int push_b;
} t_data;

void ft_push(t_data *numb)
{
	printf("pb\n");
	numb->b++;
	numb->limita++;
	numb->push_b++;
}

int	*ft_rotate(t_data *numb)
{
	int i;
	int temp;

	i = numb->limita;
	temp = numb->list_a_bin[i];
	while (i + 1 < numb->length)
	{
		numb->list_a_bin[i] = numb->list_a_bin[i + 1];
		i++;
	}
	numb->list_a_bin[i] = temp;
	printf("ra\n");
	return (numb->list_a);
}
int	*ft_rotate_a(t_data *numb)
{
	int i;
	int temp;

	i = numb->limita;
	temp = numb->list_b[i];
	while (i + 1 < numb->length)
	{
		numb->list_b[i] = numb->list_b[i + 1];
		i++;
	}
	numb->list_b[i] = temp;
	return (numb->list_a);
}

void ft_push_a(t_data *numb)
{
	printf("pa\n");
	numb->push_b--;
	numb->b--;
	numb->limita--;
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
	if (s[0] == '0')
		return (0);
	while (s[i])
	{
		num *= 10;
		num = s[i] - 48 + num;
		i++;
	}
	return (num * sign);
}

int ft_bin(int n)
{
	int i;
	int j;
	int num;
	int exp;

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

int *ft_brute_sort(int *num, int len)
{
	int i;
	int temp;

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

void ft_twolist(char **args, int argv, t_data *numb)
{
	int i;

	i = 1;
	numb->list_a = malloc(sizeof(int *) * argv);
	numb->list_b = malloc(sizeof(int *) * argv);
	numb->list_binary = malloc(sizeof(int *) * argv);
	while (args[i])
	{
		numb->list_a[i - 1] = ft_atoi(args[i]);
		numb->list_b[i - 1] = numb->list_a[i - 1];
		i++;
	}
}

int ft_bin_length(t_data *numb)
{
	if (numb->length <= 2)
		return (1);
	if (numb->length <= 4)
		return (2);
	if (numb->length <= 8)
		return (3);
	if (numb->length <= 16)
		return (4);
	if (numb->length <= 32)
		return (5);
	if (numb->length <= 64)
		return (6);
	if (numb->length <= 128)
		return (7);
	if (numb->length <= 256)
		return (8);
	if (numb->length <= 512)
		return (9);
	if (numb->length <= 1024)
		return (10);
	if (numb->length <= 2048)
		return (11);
	return (12);
}

void ft_binary_sort(t_data *numb, int j, int exp)
{
	int i;
	int k;

	i = 0;
	k = 0;
	while (k < numb->length)
	{
		if ((numb->list_a_bin[i]>>j)&1 == 1)
		{
			ft_rotate(numb);
			ft_rotate_a(numb);
		}
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

void ft_final_check(t_data *numb)
{
	int i;
	
	i = 0;
	while (i < numb->length)
	{
		if (numb->list_a_bin[i] != numb->num_bin[i])
		{
			ft_rotate(numb);
			ft_rotate_a(numb);
		}
		else
		{
			ft_push(numb);
			i++;
		}
	}
	while (numb->limita > 0)
		ft_push_a(numb);
}

void ft_binary(t_data *numb)
{
	int bits;
	int i;
	int j;
	int exp;

	i = 0;
	bits = ft_bin_length(numb);
	while (i < bits)
	{
		exp = 1;
		j = i + 1;
		while (--j != 0)
			exp *= 10;
		ft_binary_sort(numb, i, exp);
		i++;
	}
	ft_final_check(numb);
}

void ft_binary_list(t_data *numb)
{
	int i;
	int j;

	numb->list_a_bin = malloc(sizeof(int *) * numb->length);
	numb->num_bin = malloc(sizeof(int *) * numb->length);
	i = 0;
	while (i < numb->length)
	{
		j = 0;
		while (numb->num[j] != numb->list_a[i])
			j++;
		numb->list_a_bin[i] = ft_bin(j);
		numb->list_binary[i] = j;
		numb->num_bin[i] = ft_bin(i);
		i++;
	}
}

int *ft_swapper(char **args, int argv, t_data *numb)
{
	int i;
	int j;
	int *num;
	
	j = 0;
	if (!numb->num)
	{
		num = malloc(sizeof(int*) * (argv - 1));
		i = 0;
		while (i<argv - 1)
		{
			num[i] = ft_atoi(args[i+1]);
			i++;
		}
	}
	numb->length = i;
	numb->num = num;
	while(j++ < i)
		numb->num = ft_brute_sort(numb->num, i - 1);
	ft_twolist(args, argv, numb);
	ft_binary_list(numb);
	// ft_solver(numb);
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

	numb.num = NULL;
	numb.b = 0;
	numb.limita = 0;
	numb.push_b = 0;
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
	numb.num = ft_swapper(argc, argv, &numb);
	i = 0;
	ft_binary(&numb);
	while (i < numb.length)
	{
		// printf("%d", numb.length);
		// printf("Correct:%d list binry: %d My Answer: %d a-bin: %d \n", numb.num[i],numb.list_binary[i], numb.list_b[i], numb.list_a_bin[i]);
		i++;
	}
	return (0);
}
