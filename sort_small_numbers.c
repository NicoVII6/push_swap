/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:07:10 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 16:09:35 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


void	three_numb_sort(t_stack **stack)
{
	//db_show_stack(stack, 0);
	if (is_sorted(stack))
			return;
	// 2 1 3
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data < (*stack)->next->next->data)
		&& ((*stack)->next->next->data > (*stack)->data))
	{
		swap_a(stack);
		//db_show_stack(stack, 0);
	}
	// 3 2 1
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		swap_a(stack);
		reverse_rotate_a(stack);
		//db_show_stack(stack, 0);
	}
	// 3 1 2
	else if (((*stack)->data > (*stack)->next->data)
		&& ((*stack)->next->data < (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		rotate_a(stack);
		//db_show_stack(stack, 0);
	}
	// 1 3 2
	else if (((*stack)->data < (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data > (*stack)->data))
	{
		swap_a(stack);
		rotate_a(stack);
		//db_show_stack(stack, 0);
	}
	// 2 3 1 
	else if (((*stack)->data < (*stack)->next->data)
		&& ((*stack)->next->data > (*stack)->next->next->data)
		&& ((*stack)->next->next->data < (*stack)->data))
	{
		reverse_rotate_a(stack);
		//db_show_stack(stack, 0);
	}
}

void	four_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		return;
	push_b(stack_a, stack_b);
	three_numb_sort(stack_a);
	push_a(stack_b, stack_a);
	//db_show_stack(stack_a, stack_b);
	if ((*stack_a)->data < (*stack_a)->next->data)
		return; // the stack is sorted
	// 2 1 3 4
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data < (*stack_a)->next->next->data))
		swap_a(stack_a);
	// 3 1 2 4
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->next->data))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	// 4 1 2 3
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data))
		rotate_a(stack_a);
}

void	five_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	if (is_sorted(stack_a))
		exit(1);
	push_b(stack_a, stack_b);
	//db_show_stack(stack_a, stack_b);
	four_numb_sort(stack_a, stack_b); // envoie les 4 nb de stack_a plus 1 dans stack_b
	// retourne stack_a avec les 4 nb de stack_a plus celui dans stack_b
	//db_show_stack(stack_a, stack_b);
	push_a(stack_b, stack_a); // renvoie le nb de la stack_b dans stack_a
	//db_show_stack(stack_a, stack_b);
	// algo de tri pour 5 nb avec le nb du premier node a inserer parmi les 4 nb des nodes
	// suivants deja tries
	if ((*stack_a)->data < (*stack_a)->next->data)
		return; // the stack is sorted
	// 2 1 3 4 5
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data < (*stack_a)->next->next->data))
		swap_a(stack_a);
	// 3 1 2 4 5
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data < (*stack_a)->next->next->next->data))
	{
		swap_a(stack_a);
		swap_a(stack_a);
	}
	// 4 1 2 3 5
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data))
	{
		reverse_rotate_a(stack_a);
		swap_a(stack_a);
		rotate_a(stack_a);
		rotate_a(stack_a);
	}
	// 5 1 2 3 4
	else if (((*stack_a)->data > (*stack_a)->next->data) && ((*stack_a)->data > (*stack_a)->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->data)
		&& ((*stack_a)->data > (*stack_a)->next->next->next->next->data))
		rotate_a(stack_a);
}