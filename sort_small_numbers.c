/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_numbers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 13:07:10 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/12 15:08:57 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	three_numb_sort(t_stack **stack)
{
	if (is_sorted(stack))
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
	//print_list(stack);
	//db_show_stack(stack_a, 0);
}

void	four_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	three_numb_sort(stack_a);
	push_a(stack_b, stack_a);
	if ((*stack_a)->data < (*stack_a)->next->data)
		exit(1); // the stack is sorted
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
		swap_a(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->next->data)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->next->data)
		rotate_a(stack_a);
}

void	five_numb_sort(t_stack **stack_a, t_stack **stack_b)
{
	push_b(stack_a, stack_b);
	//db_show_stack(stack_a, stack_b);
	four_numb_sort(stack_a, stack_b); // envoie les 4 nb de stack_a plus 1 dans stack_b
	// retourne stack_a avec les 4 nb de stack_a plus celui dans stack_b
	push_a(stack_b, stack_a); // renvoie le nb de la stack_b dans stack_a
	//db_show_stack(stack_a, stack_b);
	// algo de tri pour 5 nb avec le nb du premier node a inserer parmi les 4 nb des nodes
	// suivants deja tries
	if ((*stack_a)->data < (*stack_a)->next->data)
		exit(1); // the stack is sorted
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data < (*stack_a)->next->next->data)
		swap_a(stack_a);
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->data < (*stack_a)->next->next->next->data)
	{
		swap_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->next->data)
	{
		rotate_a(stack_a);
		swap_a(stack_a);
	}
	else if ((*stack_a)->data > (*stack_a)->next->data && (*stack_a)->data > (*stack_a)->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->next->data
		&& (*stack_a)->data > (*stack_a)->next->next->next->next->data)
		rotate_a(stack_a);
}