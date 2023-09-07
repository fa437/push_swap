/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:57 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:47 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* selection sort */
void	temp_sort(int *temp_stack, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (temp_stack[i] > temp_stack[j])
			{
				temp = temp_stack[i];
				temp_stack[i] = temp_stack[j];
				temp_stack[j] = temp;
			}
			j++;
		}
		i++;
	}
}

/* three elements to sort */
void	three_elements(t_list *three)
{
	if (three->a[0] > three->a[1] && three->a[0] < three->a[2] 
		&& three->a[1] < three->a[2])
		swap_a(three);
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2] 
		&& three->a[1] > three->a[2])
	{
		swap_a(three);
		reverse_rotate_a(three);
	}
	if (three->a[0] > three->a[1] && three->a[0] > three->a[2] 
		&& three->a[1] < three->a[2])
		rotate_a(three);
	if (three->a[0] < three->a[1] && three->a[0] < three->a[2] 
		&& three->a[1] > three->a[2])
	{
		swap_a(three);
		rotate_a(three);
	}
	if (three->a[0] < three->a[1] && three->a[0] > three->a[2] 
		&& three->a[1] > three->a[2])
		reverse_rotate_a(three);
}

/* cheeck which sort to use */
int	sort_method(t_list *stack, int size)
{
	if (sort_order(stack->a, stack->size_a, 0) == 0)
	{
		if (size == 2)
			swap_a(stack);
		else if (size == 3)
			three_elements(stack);
		else
			quicksort_stack_a(stack, size, 0);
	}
	return (0);
}

/* push to stack a or stack b (0 == stack b, else if == stack a) */
int	ft_push(t_list *stack, int size, int push)
{
	if (push == 0)
		push_b(stack);
	else
		push_a(stack);
	size--;
	return (size);
}
