/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:36:53 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:36 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* function for freeing stack and error message */
void	error_condition(int *stack)
{
	free (stack);
	write (2, "Error\n", 6);
	exit(1);
}

/* atoi for string to integer with error cherker
	to check for all non numbers */
int	atoi_push_swap(char *str, int *stack)
{
	unsigned int		i;
	int					sign;
	unsigned long int	numb;

	i = 0;
	numb = 0;
	sign = 1;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			error_condition(stack);
		numb = (str[i] - '0') + (numb * 10);
		i++;
	}
	if ((numb > 2147483648 && sign == -1)
		|| (numb > 2147483647 && sign == 1))
		error_condition(stack);
	return (numb * sign);
}

/* strlen to check length of strings in the array */
size_t	strlen_push_swap(char **av)
{
	size_t	len;

	len = 0;
	while (av[len] != NULL)
	{
		len++;
	}
	return (len);
}

/* check sort order, either ascending or descending order */
int	sort_order(int *stack, int size, int order)
{
	int	i;

	if (order == 0)
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] > stack[i])
				return (0);
			i++;
		}
		return (1);
	}
	else
	{
		i = 1;
		while (i < size)
		{
			if (stack[i - 1] < stack[i])
				return (0);
			i++;
		}
		return (1);
	}
}

/* check for duplicate num */
void	check_duplicate_num(int *stack, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (stack[i] == stack[j])
			{
				error_condition(stack);
			}
			j++;
		}
		i++;
	}
}
