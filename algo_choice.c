/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:56:39 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 17:56:57 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc);

void	algo_choice(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 1)
		return ;
	if (argc == 2)
	{
		if (!is_sorted(stack_a))
			rotate_a(stack_a);
	}
	else if (argc >= 3 && argc <= 5)
	{
		if (!is_sorted(stack_a))
			small_numb_sort(stack_a, stack_b, argc);
	}
	else
	{
		if (!is_sorted(stack_a))
			radix_sort(stack_a, stack_b);
	}
}

t_stack	*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 3)
		three_numb_sort(stack_a);
	else if (argc == 4)
		four_numb_sort(stack_a, stack_b);
	else
		five_numb_sort(stack_a, stack_b);
	return (*stack_a);
}
