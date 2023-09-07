/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:41 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:49 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*swap a - swap the first 2 elements at the top of stack a*/
void	swap_a(t_list *stack)
{
	int	temp;

	if (stack->size_a < 2)
		return ;
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	write(1, "sa\n", 3);
}

/*swap b - swap the first 2 elements at the top of stack b*/
void	swap_b(t_list *stack)
{
	int	temp;

	if (stack->size_b < 2)
		return ;
	temp = 0;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "sb\n", 3);
}

/*swap sa and sb at the same time.*/
void	swap_both(t_list *stack)
{
	int	temp;

	if (stack->size_a && stack->size_b < 2)
		return ;
	temp = 0;
	temp = stack->a[0];
	stack->a[0] = stack->a[1];
	stack->a[1] = temp;
	temp = stack->b[0];
	stack->b[0] = stack->b[1];
	stack->b[1] = temp;
	write(1, "ss\n", 3);
}
