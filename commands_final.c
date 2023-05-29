/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/23 17:44:07 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	first = *stack;
	second = (*stack)->next;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first->next = second->next;
	second->next = first;
	*stack = second;
	write (1, "sa\n", 3);
}

// bottom node goes to top
// while loop to traverse to the last two elements of the stack
void	reverse_rotate_a(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	if (ft_stksize(*stack) >= 2)
	{
		last = *stack;
		second_last = NULL;
		while (last->next != NULL)
		{
			second_last = last;
			last = last->next;
		}
		last->next = *stack;
		*stack = last;
		second_last->next = NULL;
		write(1, "rra\n", 4);
	}
}

// top node goes to bottom
void	rotate_a(t_stack **stack)
{
	int		value;
	t_stack	*r_node;
	t_stack	*temp;

	if (ft_stksize(*stack) >= 2)
	{
		value = ft_stkpop(stack);
		r_node = ft_stknew(value);
		temp = (*stack);
		while ((*stack)->next)
			*stack = (*stack)->next;
		(*stack)->next = r_node;
		(*stack) = temp;
		write (1, "ra\n", 3);
	}
}

// new_node->next : set the next pointer of new_node to the top of stack_b
// *stack_a : update stack_b to point to the new node
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*new_node;

	top_a = ft_stkpop_push(stack_a);
	new_node = ft_stknew(top_a->data);
	free(top_a);
	new_node->next = *stack_b;
	*stack_b = new_node;
	write(1, "pb\n", 3);
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*top_b;
	t_stack	*new_node;

	top_b = ft_stkpop_push(stack_b);
	new_node = ft_stknew(top_b->data);
	free(top_b);
	new_node->next = *stack_a;
	*stack_a = new_node;
	write(1, "pa\n", 3);
}
