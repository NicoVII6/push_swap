/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/24 18:21:40 by ndecotti         ###   ########.fr       */
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

// head node goes to bottom
// retourne un pointeur sur le haut de la stack
void	rotate_a(t_stack **stack)
{
	t_stack	*to_move;
	t_stack	*temp;
	int		content;

	temp = *stack; // garde en memoire head de la stack
	if ((*stack)->next != NULL)
	{
		content = ft_stkpop(stack);
		to_move = ft_stknew(content);
		while ((*stack)->next)
		{
			*stack = (*stack)->next;
		}
		(*stack)->next = to_move;
		*stack = temp; // revient au top de la stack
	}
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

void	push_b_algo(int min, t_stack **stack_b)
{
	if (!ft_stkisempty(*stack_b))
	{
		ft_stkpush(stack_b, min);
	}
	write (1, "pb\n", 3);
}

void	push_a_algo(int min, t_stack **stack_a)
{
	if (!ft_stkisempty(*stack_a))
		ft_stkpush(stack_a, min);
	write (1, "pa\n", 3);
}