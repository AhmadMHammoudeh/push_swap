/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ahhammou <ahhammou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:41:44 by ahhammou          #+#    #+#             */
/*   Updated: 2022/01/25 07:45:03 by ahhammou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data {
	int	*num;
	int	*num_bin;
	int	limita;
	int	limitb;
	int	*list_a;
	int	*list_a_bin;
	int	*list_b;
	int	*list_binary;
	int	length;
	int	b;
	int	flag_int;
	int	j;
	int	push_b;
}	t_data;

int		check_position(t_data *numb);
int		ft_check_input(char *arg);
int		ft_errors(t_data *numb, char **argc, int i);
void	ft_initial(t_data *numb);
void	ft_sorter_three(t_data *numb, int i);
void	ft_sort_three(t_data *numb);
void	ft_sortest_five(t_data *numb);
void	ft_sorter_five(t_data *numb);
void	ft_sort_five(t_data *numb);
long	ft_atoi(char *s, t_data *numb);
int		ft_bin(int n);
void	ft_twolist(char **args, int argv, t_data *numb);
int		ft_bin_length(t_data *numb);
void	ft_binary_list(t_data *numb);
int		*ft_brute_sort(int *num, int len);
void	ft_binary_sort(t_data *numb, int j);
void	ft_final_check(t_data *numb);
void	ft_binary(t_data *numb);
int		*ft_swapper(char **args, int argv, t_data *numb);
void	ft_swap(t_data *numb, int i);
void	ft_push(t_data *numb);
int		*ft_rotate(t_data *numb);
void	ft_rotate_r(t_data *numb);
void	ft_push_a(t_data *numb);

#endif
