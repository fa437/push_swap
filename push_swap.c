/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/19 15:28:11 by fasare            #+#    #+#             */
/*   Updated: 2023/08/08 13:32:37 by fasare           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "libft/libft.h"

/* push swap implementation */
void	push_swap(char **av)
{
	t_list		stack;
	int			size;
	int			i;

	i = -1;
	size = strlen_push_swap(av);
	stack.a = (int *)malloc(size * sizeof(int));
	if (!stack.a)
		return ;
	stack.size_a = size;
	stack.b = (int *)malloc(size * sizeof(int));
	if (!stack.b)
	{
		free(stack.a);
		return ;
	}
	stack.size_b = 0;
	while (++i < size)
		stack.a[i] = atoi_push_swap(av[i], stack.a);
	check_duplicate_num(stack.a, size);
	sort_method(&stack, size);
	free(stack.a);
	free(stack.b);
}

int	main(int ac, char **av)
{
	if (ac > 1)
	{
		av++;
		if (ac == 2)
		{
			av = ft_split(*av, ' ');
			if (!av)
			{
				return (1);
			}
		}
		push_swap(av);
		if (ac == 2)
			free (av);
	}
	return (0);
}
