/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fasare <fasare@student.42wolfsburg.de>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/16 13:37:04 by fasare            #+#    #+#             */
/*   Updated: 2023/08/14 15:06:27 by fasare           ###   ########.fr       */
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
