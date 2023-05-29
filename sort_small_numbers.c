/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:07:10 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/25 14:33:30 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// 2 1 3
// 3 2 1
// 3 1 2
// 1 3 2
// 2 3 1
void	three_numb_sort(t_stack **stack)
{
	int	a;
	int	b;
	int	c;

	a = (*stack)->data;
	b = (*stack)->next->data;
	c = (*stack)->next->next->data;
	if (is_sorted(stack))
		return ;
	if (a > b && b < c && c > a)
		swap_a(stack);
	else if (a > b && b > c && c < a)
		execute_move(stack);
	else if (a > b && b < c && c < a)
		rotate_a(stack);
	else if (a < b && b > c && c > a)
		execute_move2(stack);
	else
		reverse_rotate_a(stack);
}

// 2 1 3 4
// 3 1 2 4
// 4 1 2 3
void	four_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	three_numb_sort(stack_a);
	push_a(stack_b, stack_a);
	if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->data))
		swap_a(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->next->data))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data))
		rotate_a(stack_a);
}

void	five_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (!is_sorted(stack_a))
	{
		while ((*stack_a)->data != 0)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		while ((*stack_a)->data != 1)
			rotate_a(stack_a);
		push_b(stack_a, stack_b);
		three_numb_sort(stack_a);
		push_a(stack_a, stack_b);
		push_a(stack_a, stack_b);
	}
}

// 2 1 3 4 5
// 3 1 2 4 5
// 4 1 2 3 5
// 5 1 2 3 4
/*
void	five_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	four_numb_sort(stack_a, stack_b);
	push_a(stack_b, stack_a);
	if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->data))
		swap_a(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->next->data))
		execute_move3(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->next->next->data))
		execute_move4(stack_a);
	else if (((*stack_a)->data > (*stack_a)->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->next->data))
		rotate_a(stack_a);
}
*/
