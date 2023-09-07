/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quick_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:01 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:43 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* Quick Sort for 3 & 2 num */
void	quicksort_three_num(t_list *stack, int len)
{
	if (len == 3 && stack->size_a == 3)
		three_elements(stack);
	else if (len == 2)
	{
		if (stack->a[0] > stack->a[1])
			swap_a(stack);
	}
	else if (len == 3)
	{
		while (len != 3 || !(stack->a[0] < stack->a[1]
				&& stack->a[1] < stack->a[2]))
		{
			if (len == 3 && stack->a[0] > stack->a[1] && stack->a[2])
				swap_a(stack);
			else if (len == 3 && !(stack->a[2] > stack->a[0] 
					&& stack->a[2] > stack->a[1]))
				len = ft_push(stack, len, 0);
			else if (stack->a[0] > stack->a[1])
				swap_a(stack);
			else if (len++)
				push_a(stack);
		}
	}
}

/* sorting b stack with 3 elememts */
int	sort_b(t_list *stack, int len)
{
	if (len == 1)
		push_a(stack);
	else if (len == 2)
	{
		if (stack->b[0] < stack->b[1])
			swap_b(stack);
		while (len--)
			push_a(stack);
	}
	else if (len == 3)
	{
		while (len || !(stack->a[0] < stack->a[1] && stack->a[1] < stack->a[2]))
		{
			if (len == 1 && stack->a[0] > stack->a[1])
				swap_a(stack);
			else if (len == 1 || (len >= 2 && stack->b[0] > stack->b[1])
				|| (len == 3 && stack->b[0] > stack->b[2]))
				len = ft_push(stack, len, 1);
			else
				swap_b(stack);
		}
	}
	return (0);
}

/* median of elements */
int	median(int *pivot, int *stack, int size)
{
	int	*temp;
	int	i;

	if (size <= 0 || pivot == NULL || stack == NULL)
		return (0);
	temp = (int *)malloc(size * sizeof(int));
	if (temp == NULL)
		return (0);
	i = 0;
	while (i < size)
	{
		temp[i] = stack[i];
		i++;
	}
	temp_sort(temp, size);
	*pivot = temp[size / 2];
	free (temp);
	return (1);
}

/* quick sort at stack a */
int	quicksort_stack_a(t_list *stack, int len, int rotation_count)
{
	int	pivot;
	int	numb;

	if (sort_order(stack->a, len, 0) == 1)
		return (1);
	numb = len;
	if (len <= 3)
	{
		quicksort_three_num(stack, len);
		return (1);
	}
	if (!median(&pivot, stack->a, len))
		return (0);
	while (len != numb / 2 + numb % 2)
	{
		if (stack->a[0] < pivot && (len--))
			push_b(stack);
		else if (++rotation_count)
			rotate_a(stack);
	}
	while (numb / 2 + numb % 2 != stack->size_a && rotation_count--)
		reverse_rotate_a(stack);
	return (quicksort_stack_a(stack, numb / 2 + numb % 2, 0)
		&& quicksort_stack_b(stack, numb / 2, 0));
	return (1);
}

/* quick sort at stack b */
int	quicksort_stack_b(t_list *stack, int len, int rotation_count)
{
	int	pivot;
	int	numb;

	if (sort_order(stack->b, len, 1) == 1)
		while (len--)
			push_a(stack);
	if (len <= 3)
	{
		sort_b(stack, len);
		return (1);
	}
	numb = len;
	if (!median(&pivot, stack->a, len))
		return (0);
	while (len != numb / 2 + numb % 2)
	{
		if (stack->b[0] < pivot && (len--))
			push_a(stack);
		else if (++rotation_count)
			rotate_b(stack);
	}
	while (numb / 2 != stack->size_b && rotation_count--)
		reverse_rotate_b(stack);
	return (quicksort_stack_a(stack, numb / 2 + numb % 2, 0)
		&& quicksort_stack_b(stack, numb / 2, 0));
}
/*Quick Sort Pivot Algorithm
Step 1 Choose the highest index value has pivot
Step 2 Take two variables to point left and right of the list excluding pivot
Step 3 left points to the low index
Step 4 right points to the high
Step 5 while value at left is less than pivot move right
Step 6 while value at right is greater than pivot move left
Step 7 if both step 5 and step 6 does not match swap left and right
Step 8 if left >= right, the point where they met is new pivot
Quick Sort Algorithm
Step 1 Make the right-most index value pivot
Step 2 partition the array using pivot value
Step 3 quicksort left partition recursively
Step 4 quicksort right partition recursively
*/
