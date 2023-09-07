/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:44 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:46 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* rotate a - shift up all elements of stack a by 1
      The first element becomes the last one.      */
void	rotate_a(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_a < 2)
		return ;
	i = 0;
	temp = stack->a[i];
	i++;
	while (i < stack->size_a)
	{
		stack->a[i - 1] = stack->a[i];
		i++;
	}
	stack->a[i - 1] = temp;
	write (1, "ra\n", 3);
}

/* rotate b - shift up all elements of stack b by 1
	The first element becomes the last one.         */
void	rotate_b(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_b < 2)
		return ;
	i = 0;
	temp = stack->b[i];
	i++;
	while (i < stack->size_b)
	{
		stack->b[i - 1] = stack->b[i];
		i++;
	}
	stack->b[i - 1] = temp;
	write (1, "ra\n", 3);
}

/* rotate both ra and rb at the same time.
	The first elements become the last one. */
void	rotate_both(t_list *stack)
{
	int	temp;
	int	i;

	if (stack->size_a && stack->size_b < 2)
		return ;
	i = 0;
	temp = stack->a[i];
	while (++i < stack->size_a)
		stack->a[i - 1] = stack->a[i];
	stack->a[i - 1] = temp;
	i = 0;
	temp = stack->b[i];
	while (++i < stack->size_b)
		stack->b[i - 1] = stack->b[i];
	stack->b[i - 1] = temp;
	write (1, "rr\n", 3);
}
