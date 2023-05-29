/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:10:08 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/23 16:42:35 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	bit_size(int size)
{
	int		bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}

t_stack	*radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;

	size = ft_stksize(*stack_a);
	i = 0;
	while (i < bit_size(size))
	{
		j = 0;
		while (j < size)
		{
			if ((((*stack_a)->data >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		i++;
	}
	return (*stack_a);
}
