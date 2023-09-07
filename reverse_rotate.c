/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:50 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:45 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*		reverse rotate a
shift down all elements of stack a by 1.
The last element becomes the first one. */
void	reverse_rotate_a(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_a < 2)
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	write (1, "rra\n", 4);
}

/*		reverse rotate b
shift down all elements of stack b by 1.
The last element becomes the first one. */
void	reverse_rotate_b(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_b < 2)
		return ;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	write (1, "rrb\n", 4);
}

/*		reverse rotate both
shift down all elements of stack a and b by 1.
The last element becomes the first one. */
void	reverse_rotate_both(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_a && stack->size_b < 2)
		return ;
	i = stack->size_a - 1;
	temp = stack->a[i];
	while (i)
	{
		stack->a[i] = stack->a[i - 1];
		i--;
	}
	stack->a[i] = temp;
	i = stack->size_b - 1;
	temp = stack->b[i];
	while (i)
	{
		stack->b[i] = stack->b[i - 1];
		i--;
	}
	stack->b[i] = temp;
	write (1, "rrr\n", 4);
}
