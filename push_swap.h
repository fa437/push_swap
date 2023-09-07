/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 22:40:56 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:39 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include "libft/libft.h"

typedef struct s_list
{
	int	*a;
	int	*b;
	int	size_a;
	int	size_b;
}	t_list;

/*instructions*/
void	swap_a(t_list *stack);
void	swap_b(t_list *stack);
void	swap_both(t_list *stack);
void	push_a(t_list *stack);
void	push_b(t_list *stack);
void	rotate_a(t_list *stack);
void	rotate_b(t_list *stack);
void	rotate_both(t_list *stack);
void	reverse_rotate_a(t_list *stack);
void	reverse_rotate_b(t_list *stack);
void	reverse_rotate_both(t_list *stack);

/*utils*/
void	error_condition(int *stack);
int		atoi_push_swap(char *str, int *stack);
size_t	strlen_push_swap(char **av);
int		sort_order(int *stack, int size, int order);
void	check_duplicate_num(int *stack, int size);

/* sorting */
void	temp_sort(int *temp_stack, int size);
void	three_elements(t_list *three);
int		sort_method(t_list *stack, int size);
int		ft_push(t_list *stack, int size, int push);
void	quicksort_three_num(t_list *stack, int len);
int		sort_b(t_list *stack, int len);
int		median(int *pivot, int *stack, int size);
int		quicksort_stack_a(t_list *stack, int len, int rotation_count);
int		quicksort_stack_b(t_list *stack, int len, int rotation_count);
void	push_swap(char **av);
int		main(int ac, char **av);
void	handle_error(t_list *satck, int error_message);
void	cmp_instruction(t_list *stack, char *instruction);

#endif
