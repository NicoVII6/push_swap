/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:10:08 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 18:15:40 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
int	get_max_value(t_stack **stack_a)
{
	t_stack	*temp;
	int		max;

	temp = *stack_a;
	max = (*stack_a)->data;
	while ((*stack_a)->next)
	{
		if ((*stack_a)->data > max)
			max = (*stack_a)->data;
		*stack_a = (*stack_a)->next;
	}
	*stack_a = temp;
	return (max);
}*/

static int	bit_size(int size)
{
	int		bit_max;

	bit_max = 0;
	while (size >> bit_max)
		bit_max++;
	return (bit_max);
}

t_stack		*radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		j;
	int		size;

	size = ft_stksize(*stack_a);

	i = 0;
	// tant que le nb max est a une unit superieure a 0, alors le tri continue
	while (i < bit_size(size))
	{
		j = 0;
		while (j < size)
		{
			// if the i-th bit from the right is 0, push to stack b
			if ((((*stack_a)->data >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			j++;
		}
		// move the items from stach b to stack a
		while (*stack_b)
			push_a(stack_b, stack_a); // revoir parametres
		i++;
	}
	return (*stack_a);
}