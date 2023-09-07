/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:47 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:42 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* push a - take the first element at the top of b
           and put it at the top of a.             */
void	push_a(t_list *stack)
{
	int	i;

	if (stack->size_b)
	{
		stack->size_a++;
		i = stack->size_a;
		while (--i > 0)
			stack->a[i] = stack->a[i - 1];
		stack->a[0] = stack->b[0];
		i = -1;
		stack->size_b--;
		while (++i < stack->size_b)
			stack->b[i] = stack->b[i + 1];
		write(1, "pa\n", 3);
	}
	else
		return ;
}

/* push b - take the first element at the top of b
			and put it at the top of a.            */
void	push_b(t_list *stack)
{
	int	i;

	if (stack->size_a)
	{
		stack->size_b++;
		i = stack->size_b;
		while (--i > 0)
			stack->b[i] = stack->b[i - 1];
		stack->b[0] = stack->a[0];
		i = -1;
		stack->size_a--;
		while (++i < stack->size_a)
			stack->a[i] = stack->a[i + 1];
		write (1, "pb\n", 3);
	}
	else
		return ;
}
