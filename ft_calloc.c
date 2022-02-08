/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 10:42:34 by mal-guna          #+#    #+#             */
/*   Updated: 2022/02/07 23:56:21 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*ft_memset(void *b, int c, size_t len)
{
	char	*str;
	size_t	i;

	str = (char *)b;
	i = 0;
	while (i < len)
	{
		str[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

void	ft_free(t_data *numb)
{
	if (numb->num)
		free(numb->num);
	if (numb->list_binary)
		free(numb->list_binary);
	if (numb->list_b)
		free(numb->list_b);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*new;

	new = malloc(size * count);
	if (!new)
		return (NULL);
	ft_memset(new, 0, count * size);
	return (new);
}
