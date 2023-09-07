/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:04 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:29 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/* handle errors and deallocate memory if need be. */
void	handle_error(t_list *stack, int error_message)
{
	free(stack->a);
	free(stack->b);
	if (error_message)
		write (2, "Error\n", 6);
	exit(1);
}

/* identifies the instruction and calls the 
	corresponding function to perform the associated 
	operation */
void	cmp_instruction(t_list *stack, char *instruction)
{
	if (!strcmp(instruction, "sa\n"))
		swap_a(stack);
	else if (!strcmp(instruction, "sb\n"))
		swap_b(stack);
	else if (!strcmp(instruction, "ss\n"))
		swap_both(stack);
	else if (!strcmp(instruction, "pa\n"))
		push_a(stack);
	else if (!strcmp(instruction, "pb\n"))
		push_b(stack);
	else if (!strcmp(instruction, "ra\n"))
		rotate_a(stack);
	else if (!strcmp(instruction, "rb\n"))
		rotate_b(stack);
	else if (!strcmp(instruction, "rr\n"))
		rotate_both(stack);
	else if (!strcmp(instruction, "rra\n"))
		reverse_rotate_a(stack);
	else if (!strcmp(instruction, "rrb\n"))
		reverse_rotate_b(stack);
	else if (!strcmp(instruction, "rrr\n"))
		reverse_rotate_both(stack);
	else
		handle_error(stack, 1);
}
