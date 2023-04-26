/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homemade_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:26:05 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/26 17:55:10 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// FONCTION DE PLUS DE 25 LIGNES
// A CHAQUE IF APPELER UNE FONCTION
// 1er if signifie que nombres sont deja tries
void	three_numb_sort(t_stack **stack)
{
	if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data))
			exit(1);
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data < (*stack)->next->next->data)
		&& ((*stack)->next->next->data > (*stack)->data))
	{
		swap_a(stack);
	}
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		swap_a(stack);
		reverse_rotate_a(stack);
	}
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data < (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		rotate_a(stack);
	}
	else if (((*stack)->data < (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data > (*stack)->data))
	{
		swap_a(stack);
		rotate_a(stack);
	}
	else if (((*stack)->data < (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		reverse_rotate_a(stack);
	}
}

void	four_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min_value(stack_a);
	push_b_algo(min, stack_b);
	three_numb_sort(stack_a);
	push_a_algo(min, stack_a);
}

void	five_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	min;

	min = get_min_value(stack_a);
	push_b_algo(min, stack_b);
	four_numb_sort(stack_a, stack_b);
	push_a_algo(min, stack_a);
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

// si arguments recus sans double quote
void	algo_choice(t_stack **stack_a, t_stack **stack_b, int argc)
{
	if (argc == 2)
	{
		if (!is_sorted(stack_a))
			rotate_a(stack_a);
	}
	else if (argc >= 3 && argc < 6)
	{
		small_numb_sort(stack_a, stack_b, argc);
	}
	else
	{
		decimal_to_binary(stack_a);
		radix_sort(stack_a, stack_b);
	}
}