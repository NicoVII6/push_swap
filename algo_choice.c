/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_choice.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 17:56:39 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/12 15:09:04 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack		*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc);
// si arguments recus sans double quote
// probleme avec fonction small_numb_sort
void	algo_choice(t_stack **stack_a, t_stack **stack_b, int argc)
{
	//db_show_stack(stack_a, stack_b);
	if (argc == 2)
		return; // 1 seul numero
	if (argc == 3)
	{
		if (!is_sorted(stack_a))
			rotate_a(stack_a);
	}
	else if (argc > 3 && argc <= 6)
	{
		small_numb_sort(stack_a, stack_b, argc);
		//db_show_stack(stack_a, stack_b);
	}
	else
	{
		decimal_to_binary(stack_a);
		//db_show_stack(stack_a, stack_b);
		radix_sort(stack_a, stack_b);
	}
}

t_stack		*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 4)
		three_numb_sort(stack_a);
	else if (argc == 5)
		four_numb_sort(stack_a, stack_b);
	else
		five_numb_sort(stack_a, stack_b);
	return (*stack_a);
}