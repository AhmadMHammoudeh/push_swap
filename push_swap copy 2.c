/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap copy.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:38:02 by ahhammou          #+#    #+#             */
/*   Updated: 2021/12/24 21:21:30 by ahhammou         ###   ########.fr       */
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
} t_data;


int	check_position(t_data *numb)
{
	int i;

	i = 0;
	while (numb->list_a[i] == numb->num[i] && i <= numb->length)
	{
		i++;
	}
	if (numb->list_a[i] != numb->num[i])
		return (0);
	return (1);
}

void ft_push(t_data *numb, int i)
{
	int push;
	
	numb->j = 0;
	while (numb->b <= i)
	{
		printf("pb\n");
		numb->list_b[numb->b] = numb->list_a[i - numb->b];
		numb->b++;
	}
	numb->limita = numb->b;
}

void ft_swap(t_data *numb, int i, int j)
{
	int c;

	// printf("j in swap: %d, numb->limita : %d\n", j, numb->limita);
	while (j >= numb->limita)
	{
		ft_push(numb, j);
		numb->limita++;
	}
	c = numb->list_a[i];
	numb->list_a[i] = numb->list_a[j];
	numb->list_a[j] = c;
	printf("sa\n");
}

int	*ft_rotate(t_data *numb)
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
	printf("ra\n");
	return (numb->list_a);
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
	while (num[i])
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

	i = 1;
	numb->list_a = malloc(sizeof(int *) * argv);
	numb->list_b = malloc(sizeof(int*) * argv);
	while (args[i])
	{
		numb->list_a[i - 1] = ft_atoi(args[i]);
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
	div = (numb->length - numb->limita) / 2;
	if (numb->length > 7)
		div = numb->length / 2;
	if (j - i <= div)
		ft_swap(numb, i, j);
	else
		numb->list_a = ft_rotate(numb);
}

int	ft_putchar_bin(char c)
{
	if (c > 47 && c < 58)
		write(1, &c, 1);
	return (1);
}


int	ft_putnbr_bin(unsigned int nb)
{
	int	i;

	i = ft_numlength_h(nb);
	if (nb > 1)
	{
		ft_putnbr_bin(nb / 2);
	}
	ft_putchar_bin(48 + nb % 2);
	return (i);
}

int ft_bin_length(t_data *numb)
{
	if (numb->length < 2)
		return (1);
	if (numb->length < 4)
		return (2);
	if (numb->length < 8)
		return (3);
	if (numb->length < 16)
		return (4);
	if (numb->length < 32)
		return (5);
	if (numb->length < 64)
		return (6);
	if (numb->length < 128)
		return (7);
	if (numb->length < 256)
		return (8);
	if (numb->length < 512)
		return (9);
	if (numb->length < 1024)
		return (10);
	if (numb->length < 2048)
		return (11);
	return (12);
}
void ft_binary(t_data *numb)
{
	int bits;
	int i;
	
	i = 0;
	bits = ft_bin_length(numb);
	while (i < bits)
	{
		ft_binary_sort(numb);
		i++;
	}
}
void ft_solver(t_data *numb)
{
	int i;
	int j;
	int k;

	i = 0;
	k = numb->length / 5;
	while (numb->list_a[i])
	{
		// printf("Loop : %d I: %d\n", k, i);
		if (check_position(numb)== 1)
			break;
		j = 0;
		// printf("Checking Number : %d I: %d\n", numb->list_a[i], i);
		while (numb->num[j] != numb->list_a[i])
			j++;
		if (numb->list_a[i] == numb->num[i] && i < numb->length-1)
		{
			ft_push(numb, i);
			i++;
		}
		else if (numb->list_a[i] != numb->num[i])
			ft_sort(numb, i, j);
		else
			i++;
		k++;
	}
}

int *ft_swapper(char **args, int argv, t_data *numb)
{
	int i;
	int j;
	int *num;
	
	j = 0;
	numb->limita = 0;
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
	numb->length = i - 1;
	numb->num = num;
	while(j++ < i)
	numb->num = ft_brute_sort(numb->num, i - 1);
	ft_twolist(args, argv, numb);
	ft_solver(numb);;
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
		if (check_position(&numb) == 1)
			break;
	}
	if (numb.limita > 0)
	{
		while (numb.limita >= 1)
		{
			printf("pa\n");
			numb.limita--;
		}
	}
	i = 0;
	while (numb.num[i])
	{
		j = 0;
		while(j < i)
		{
			if (numb.num[i] == numb.num[j])
				return (printf("Error, Duplicate Entry\n"));
			j++;
		}
		// printf("%d", numb.list_a[i]);
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
