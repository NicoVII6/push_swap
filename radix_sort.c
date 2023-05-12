/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:10:08 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/11 19:08:05 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
}

t_stack		*radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int		i;
	int		max;

	max = get_max_value(stack_a); // trouver la valeur max en binaire pour le radix
	//size = list_size(a);

	i = 0;
	// tant que le nb max est a une unit superieure a 0, alors le tri continue
	while ((max >> i) > 0)
	{
		while (*stack_a)
		{
			// if the i-th bit from the right is 0, push to stack b
			if ((((*stack_a)->data >> i) & 1) == 0)
				push_b(stack_a, stack_b);
			else
				rotate_a(stack_a);
			*stack_a = (*stack_a)->next;
		}
		// move the items from stach b to stack a
		while (*stack_b)
		{
			push_a(stack_b, stack_a); // revoir parametres
			*stack_b = (*stack_b)->next;
		}
		i++;
	}
	return (*stack_a);
}