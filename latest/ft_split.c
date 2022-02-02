/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/03 17:03:18 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/31 16:23:47 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count(const char *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[j])
	{
		if (s[j] != c)
		{
			i++;
			while ((s[j] != c) && s[j])
				j++;
			if (!s[j])
				break ;
		}
		j++;
	}
	return (i);
}

static char	*ft_engine(int j, int i, char const *s, char c)
{
	int		k;
	char	*ea;
	int		x;

	k = 0;
	x = i - j - 1;
	ea = (char *)ft_calloc(sizeof(char), (j + 1));
	if (!ea)
		return (NULL);
	if (s[x] == c)
		x++;
	while (s[x] != c && x != i)
		ea[k++] = s[x++];
	return (ea);
}

static void	ft_assign(char **ptr, t_data *numb, int *x, char const *s)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = 0;
	while (s[i])
	{
		j = 0;
		while (s[i] == ' ' && s[i])
			i++;
		while (s[i] && s[i++] != ' ')
			j++;
		if (j > 0)
		{
			ptr[k] = ft_engine(j, i, s, ' ');
			x[k] = ft_atoi(ptr[k], numb);
			numb->list_a[numb->input] = x[k];
			numb->list_b[numb->input] = numb->list_a[numb->input];
			k++;
			numb->input++;
		}
		free(ptr[k - 1]);
	}
}

static int	*ft_split_engine(char const *s, char c, t_data *numb)
{
	char	**ptr;
	int		*x;

	x = malloc(sizeof(int) * (count(s, c) + 1));
	ptr = (char **)malloc((count(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	ft_assign(ptr, numb, x, s);
	free(ptr);
	free(x);
	return (numb->list_b);
}

int	*ft_split(char const *s, char c, t_data *numb)
{
	if (!s)
		return (NULL);
	return (ft_split_engine(s, c, numb));
}
