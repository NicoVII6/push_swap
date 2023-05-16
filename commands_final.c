/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 16:10:52 by ndecotti         ###   ########.fr       */
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

void	push_b(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*top_a;
	t_stack	*new_node;

	top_a = ft_stkpop_push(stack_a);
	new_node = ft_stknew(top_a->data); // ajoute new_node to stack_b
	new_node->next = *stack_b; // set the next pointer of new_node to the top of stack_b
	*stack_b = new_node; // update stack_b to point to the new node
}

void	push_a(t_stack **stack_b, t_stack **stack_a)
{
	t_stack	*top_b;
	t_stack	*new_node;

	top_b = ft_stkpop_push(stack_b);
	new_node = ft_stknew(top_b->data);
	new_node->next = *stack_a;
	*stack_a = new_node;
}