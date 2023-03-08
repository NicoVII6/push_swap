/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:11:35 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:07 by ndecotti         ###   ########.fr       */
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
/* think about the memory allocation all around the project, 2 solutions : the stack_size way
 * or the dynamic allocation */

// intialize a new stack
void	initialize_stack(stack *s)
{
	s->top = -1;
}

// check if stack is empty
int		is_empty(stack *s)
{
	return s->top = -1;
}

// check if stack is full
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
	s->top++; // enough to "create" the new top item where to add the value
	s->items[s->top] = data; // add the value into the top
}

// Pop and delete an item from the stack
int		pop(stack *s)
{
	if (is_empty(s))
	{
		printf("Error\n");
		exit(1);
	}
	int	data = s->items[s->top];
	s->top--; // enough to "delete". at least to actualize the stack after the move 
	return data;
}

// move the top element from stack a to the top of stack b
// use the combination of pop and push functions
// for pb, we make pop a, then push b
// for pa, we make pop b, then push a
void	push_b(stack *a, stack *b)
{
	if (is_empty(a))
	{
		printf("Error\n");
		exit(1);
	}
	int	data;

	write(1, "pb\n", 3);
	data = pop(a);
	push(b, data);
}

// move the top element from stack b to the top of stack a
void	push_a(stack *b, stack *a)
{
	if (is_empty(b))
	{
		printf("Error\n");
		exit(1);
	}
	int	data;

	write(1, "pa\n", 3);
	data = pop(b);
	push(a, data);
}

// function to swap the two top elements of the stack
void	swap_a(stack *a)
{
	if (a->top < 1) // check if the is at least 2 values in the stack
		return;
	write(1, "sa\n", 3);
	int	temp = a->items[a->top];
	a->items[a->top] = a->items[a->top-1]; // top-1 = 2e element
	a->items[a->top-1] = temp;
}

void	swap_b(stack *b)
{
	if (b->top < 1)
		return;
	write(1, "sb\n", 3);
	int	temp = b->items[b->top];
	b->items[b->top] = b->items[b->top-1];
	b->items[b->top-1] = temp;
}

// top number goes to bottom
void	rotate_a(stack *a)
{
	if (a->top < 1)
		return;
	int	temp;
	int	i;

	write(1, "ra\n", 3);
	temp = a->items[a->top];
	i = a->top;
	while (i > 0)
	{
		a->items[i] = a->items[i - 1]; // decale de 1 step vers le haut l'ensemble des valeurs 
		i--;						// jusqu'a arriver a la derniere valeur
	}
	a->items[0] = temp; // remplace derniere valeur par 1ere valeur du top de la stack
}
// Top to bottom
void	rotate_b(stack *b)
{
	if (b->top < 1)
		return;
	int	temp;
	int	i;

	write(1, "rb\n", 3);
	temp = b->items[b->top];
	i = b->top;
	while (i > 0)
	{
		b->items[i] = b->items[i - 1];
		i--;
	}
	b->items[0] = temp;
}
// Bottom to top
void	rev_rotate_a(stack *a)
{
	if (a->top < 1)
		return;
	int	temp;
	int	i;

	write(1, "rra\n", 4);
	temp = a->items[0]; // put the last value in a temporary variable
	i = 0;
	while (i < a->top)
	{
		a->items[i] = a->items[i + 1];
		i++;
	}
	a->items[a->top] = temp;
}

void	rev_rotate_b(stack *b)
{
	if (b->top < 1)
		return;
	int	temp;
	int	i;

	write(1, "rrb\n", 4);
	temp = b->items[0];
	i = 0;
	while (i < b->top)
	{
		b->items[i] = b->items[i + 1];
		i++;
	}
	b->items[b->top] = temp;
}