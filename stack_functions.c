/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:46:36 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 15:20:36 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/* main rule of stack : Last In First Out !! */

// retourne un pointeur sur l'element ajouté a la stack
t_stack	*ft_stknew(int value)
{
	t_stack		*node;

	node = malloc(sizeof(t_stack));
	if (!node)
		return (NULL);
	node->data = value;
	node->next = NULL;
	return (node);
}

t_stack	*ft_stkpop_push(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	*stack = (*stack)->next;
	return (temp);
}

// removes from the stack the most recent added element
// and returns the content of the stack popped
int	ft_stkpop(t_stack **stack)
{
	t_stack	*temp;
	int		content;

	if (ft_stkisempty(*stack))
		return (0);
	temp = *stack;
	*stack = (*stack)->next;
	content = temp->data;
	free(temp);
	return (content);
}

// adds an new node to the stack
void	ft_stkpush(t_stack **stack, int data)
{
	t_stack	*new_node;

	new_node = ft_stknew(data);
	new_node->next = *stack;
	*stack = new_node;
}

// nettoie la stack de tous ses elements
void	ft_stkclear(t_stack **stack)
{
	t_stack	*temp;

	while (*stack)
	{
		temp = *stack;
		*stack = (*stack)->next;
		free(temp);
	}
}
