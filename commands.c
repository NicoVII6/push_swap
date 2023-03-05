/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:11:35 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/05 17:33:18 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A Retravailler et ameliorer pour que ca fit avec les autres fonctions
// ici on utilise a fixed sized array stack memory instead of dynamic memory allocation
// EST CE QUE CETTE METHODE EST AUTORISEE ??

#include "push_swap.h"

#define STACK_SIZE 10000

typedef struct stack {
	int	top;
	int	items[STACK_SIZE];
} stack;

// intialize a new stack
void	initialize_stack(stack *s)
{
	s->top = -1;
}

int		is_empty(stack *s)
{
	return s->top = -1;
}

int		is_full(stack *s)
{
	return s->top = STACK_SIZE -1;
}

// Push an item onto the stack
void	push(stack *s, int data)
{
	if (is_full(s))
	{
		printf("Error\n"); // sur la sortie d'erreur
		exit(1);
	}
	s->top++;
	s->items[s->top] = data;
}

// Pop an item from the stack
int		pop(stack *s)
{
	if (is_empty(s))
	{
		printf("Error\n");
		exit(1);
	}
	int	data = s->items[s->top];
	s->top--;
	return data;
}

// function to swap the two top elements of the stack
// stay with this form, if not working, do 2 different for stack a and b
void	swap(stack *s)
{
	if (s->top < 1) // ?
		return;
	int	temp = s->items[s->top];
	s->items[s->top] = s->items[s->top-1]; // top-1 = 2e element
	s->items[s->top-1] = temp;
}

// Function to move the top element from stack a to stack b
void	push_b(stack *a, stack *b)
{
	if (is_empty(a))
	{
		printf("Error\n");
		exit(1);
	}
	int	data;

	data = pop(a);
	push(b, data);
} // TROUVER ENDROIT OU METTRE LE PRINT DE LA COMMANDE EXECUTEE

void	push_a(stack *b, stack *a)
{
	if (is_empty(b))
	{
		printf("Error\n");
		exit(1);
	}
	int	data;

	data = pop(b);
	push(a, data);
}

// top number goes to bottom
void	rotate_a(stack *a)
{
	if (a->top < 1) // ??
		return;
	int	temp;
	int	i;

	temp = a->items[a->top];
	i = a->top;
	while (i > 0)
	{
		a->items[i] = a->items[i-1];
		i--;
	}
	a->items[0] = temp;
}

void	rotate_b(stack *b)
{
	if (b->top < 1)
		return;
	int	temp;
	int	i;

	temp = b->items[b->top];
	i = b->top;
	while (i > 0)
	{
		b->items[i] = b->items[i-1];
		i--;
	}
	b->items[0] = temp;
}