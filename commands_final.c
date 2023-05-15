/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/15 21:42:43 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_stack **stack)
{
	int		first;
	int		second;

	if ((*stack)->next != NULL)
	{
		first = ft_stkpop(stack);
		second = ft_stkpop(stack);
		ft_stkpush(stack, first);
		ft_stkpush(stack, second);
	}
	write(1, "sa\n", 3);
}

// top node goes to bottom
void rotate_a(t_stack **stack)
{
	// Pop the top element and store its value.
	int value = (*stack)->data;
	t_stack *temp = *stack;
	*stack = (*stack)->next;
	free(temp); // supprime premier noeud apres avoir enregistre sa data
	t_stack *last = *stack;
	// Traverse the stack to the last element.
	while (last->next != NULL) {
		last = last->next;
	}
	// Create a new node with the stored value and set its `next` pointer to `NULL`.
	t_stack *new_node = (t_stack *) malloc(sizeof(t_stack));
	if (new_node == NULL)
		exit (1); // verifier si bonne sortie
	new_node->data = value;
	new_node->next = NULL;
	// Set the `next` pointer of the current last element to the new node.
	last->next = new_node; // the top value which is rotate
	write(1, "ra\n", 3);
}

// tail node goes to top
// renvoie un pointeur sur premier element liste
void	reverse_rotate_a(t_stack **stack)
{
	t_stack	*temp;
	int		content;

	if ((*stack)->next != NULL)
	{
		temp = *stack;
		// boucle jusqu'a atteindre avant dernier noeud
		while ((*stack)->next && (*stack)->next->next)
			*stack = (*stack)->next;
		content = (*stack)->next->data; // recupere contenu dernier noeud 
		(*stack)->next = NULL; // deconnecte dernier noeud
		ft_stkpush(&temp, content); // permet de push au top de la stack grace a temp
		(*stack) = temp; // revient au top d la stack
		write (1, "rra\n", 4);
	}
}

// top element from stack a goes to head of stack b
void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	int		content;

	if (!ft_stkisempty(*stack_b))
	{
		content = ft_stkpop(stack_a);
		ft_stkpush(stack_b, content);
	}
	write (1, "pb\n", 3);
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	int		content;

	if (!ft_stkisempty(*stack_a))
	{
		content = ft_stkpop(stack_b);
		ft_stkpush(stack_a, content);
	}
	write (1, "pa\n", 3);
}