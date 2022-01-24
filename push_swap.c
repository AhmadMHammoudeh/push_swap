/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/17 20:36:32 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "ft_printf.h"
#include "ft_strlen.c"

typedef struct s_data {
	int *num;
	int limita;
	int limitb;
	int *list_a;
	int *list_b;
	int length;
	int b;
	int j;
	int push_b;
} t_data;


int	check_position(t_data *numb)
{
	int i;

	i = 0;
	while (numb->list_b[i] == numb->num[i] && i <= numb->length)
	{
		i++;
	}
	if (numb->list_b[i] != numb->num[i])
		return (0);
	return (1);
}

void ft_push(t_data *numb, int i)
{
	int push;
	int c;
	int check;
	
	numb->j = 0;
	while (numb->b <= i)
	{
		printf("pb\n");
		check = numb->b;
		// if (check > 0 && numb->list_b[check] < numb->list_b[check - 1])
		// {
		// 	c = numb->list_b[check - 1];
		// 	numb->list_b[check - 1] = numb->list_b[check];
		// 	numb->list_b[check] = c;
		// 	printf("sb\n");
		// 	check--;
		// }
		numb->b++;
		numb->limita++;
	}
	numb->push_b++;
}

void ft_swap(t_data *numb, int i)
{
	int c;

	c = numb->list_b[i];
	numb->list_b[i] = numb->list_b[i + 1];
	numb->list_b[i + 1] = c;
	printf("sa\n");
}

void ft_swap_b(t_data *numb, int i)
{
	int c;

	c = numb->list_b[i];
	numb->list_b[i] = numb->list_b[i + 1];
	numb->list_b[i + 1] = c;
	printf("sb\n");
}

int	*ft_rotate(t_data *numb)
{
	int i;
	int temp;

	i = numb->limita;
	temp = numb->list_b[numb->limita];
	while (i < numb->length)
	{
		numb->list_b[i] = numb->list_b[i + 1];
		i++;
	}
	numb->list_b[i] = temp;
	printf("ra\n");
	return (numb->list_a);
}

int	*ft_rotate_b(t_data *numb)
{
	int i;
	int temp;

	i = 0;
	temp = numb->list_b[0];
	while (i < numb->limita)
	{
		numb->list_b[i] = numb->list_b[i + 1];
		i++;
	}
	numb->list_b[numb->limita] = temp;
	printf("rrb\n");
	return (numb->list_a);
}

void ft_rotate_r_b(t_data *numb)
{
	int i;
	int temp;

	i = numb->limita;
	temp = numb->list_b[numb->limita];
	while (i > 0)
	{
		numb->list_b[i] = numb->list_b[i - 1];
		i--;
	}
	numb->list_b[0] = temp;
	printf("rb\n");
}

void ft_rotate_r(t_data *numb)
{
	int i;
	int temp;

	temp = numb->list_b[numb->length - 1];
	i = numb->length - 1;
	while (i > numb->limita)
	{
		numb->list_b[i] = numb->list_b[i - 1];
		i--;
	}
	numb->list_b[numb->limita] = temp;
	printf("rra\n");
}

void ft_push_a(t_data *numb)
{
	int i;
	int j;

	j = 0;
	while (numb->list_a[j])
		j++;
	i = j;
	while (numb->b >= 0)
	{
		numb->list_a[numb->b] = numb->list_b[i];
		numb->b -= 1;
		i++;
	}
	while (j > 0)
	{
		ft_rotate(numb);
		j--;
	}
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
		if (s[i] == '0')
			num = 0;
		else
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
	numb->list_b = malloc(sizeof(int*) * argv);
	while (args[i])
	{
		numb->list_a[i - 1] = ft_atoi(args[i]);
		numb->list_b[i - 1] = numb->list_a[i - 1];
		i++;
	}
}

void ft_sort(t_data *numb, int i, int j)
{
	int a;
	int b;
	int div;

	a = 0;
	b = 0;
	if (check_position(numb)== 1)
		return;
	numb->list_a = ft_rotate(numb);
}

void ft_sort_three(t_data *numb)
{
	int i;
	int j;

	i = 0;
	if (numb->list_b[0] == numb->num[1] &&\
			numb->list_b[1] == numb->num[2])
	{
		ft_rotate_r(numb);
		return ;
	}
	else if (numb->list_b[0] == numb->num[0] &&\
				numb->list_b[1] == numb->num[2])
	{
		ft_swap(numb,0);
		ft_rotate(numb);
		return ;
	}
	while (i < numb->length -1)
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

int ft_solver(t_data *numb)
{
	int j;
	int c;
	int i;
	int k;
	int z;
	int chunk;

	// if(ft_check_dup(numb))
	// 	return (0);
	if (check_position(numb) == 1)
		return (3);
	chunk = 0;
	c = 0;
	if (numb->length == 3)
	{
		ft_sort_three(numb);
		return (0);
	}
	if (numb->length >= 100)
		k = numb->length / 11;
	else if (numb->length > 5)
		k = numb->length / 5;
	else
		k = numb->length;
	while (c < numb->length / k)
	{
		i = numb->limita;
		chunk += k;
		while (i + 1 < chunk)
		{
			j = 0;
			while (numb->num[i] != numb->list_b[j])
				j++;
			if (j <= chunk)
			{
				ft_push(numb, i);
				i++;
			}
			else if (j - i == 1)
				ft_swap(numb, i);
			else if (j - numb->limita > (numb->length - numb->limita) / 2)
				ft_rotate_r(numb);
			else
				ft_rotate(numb);
		}
		c++;
	}
	while (numb->limita + 2 < numb->length)
	{
		j = 0;
		while (numb->num[i] != numb->list_b[j])
			j++;
		if (j <= chunk + i)
		{
			ft_push(numb, i);
			i++;
		}
		else if (j - i == 1)
			ft_swap(numb, i);
		else if (j - numb->limita > (numb->length - numb->limita) / 2)
			ft_rotate_r(numb);
		else
			ft_rotate(numb);
	}
	return (i);
}

int *ft_swapper(char **args, int argv, t_data *numb)
{
	int i;
	int j;
	int *num;
	
	j = 0;
	numb->limitb = 0;
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
	i = 0;
	numb.num = ft_swapper(argc, argv, &numb);
	if (check_position(&numb) == 1)
		return (0);
			i = 0;
	while (i < numb.length)
	{
		j = 0;
		while (j < i)
		{
			if (numb.num[i] == numb.num[j])
				return (printf("Error, Duplicate Entry\n"));
			j++;
		}
		i++;
	}
	ft_solver(&numb);
	if (numb.limita > 0)
	{
		while (numb.limita > 0)
		{
			j = 0;
			while (numb.num[numb.limita] != numb.list_b[j])
				j++;
			if (numb.num[numb.limita] == numb.list_b[numb.limita])
			{
				printf("pa\n");
				numb.limita--;
			}
			else if (j < numb.limita / 2)
				ft_rotate_b(&numb);
			else if (j + 1 == numb.limita)
			{
				ft_swap_b(&numb, numb.limita-1);
			}
			else
				ft_rotate_r_b(&numb);
		}
	}
	i = 0;
	while (i < numb.length)
	{
		// printf("Correct:%d My Answer: %d \n", numb.num[i], numb.list_b[i]);
		i++;
	}
	free(numb.list_a);
	free(numb.list_b);
	return (0);
}
