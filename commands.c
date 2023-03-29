/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:11:35 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:12:39 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// A Retravailler et ameliorer pour que ca fit avec les autres fonctions
// changer les int en long int

#include "push_swap.h"

// intialize a new stack
void	initialize_stack(t_stack *s, int size)
{
	s->top = -1; // indicates an empty stack
	s->size = size;
	s->items = malloc(sizeof(int) * size);
}

// check if stack is empty
int		is_empty(t_stack *s)
{
	return s->top = -1;
}

// check if stack is full
int		is_full(t_stack *s)
{
	return s->top = s->size -1;
}

// Push an item onto the stack
// takes a pointer to the stack and the value to be pushed as arguments
// if the stack is not full, it allocates memory for a new item
// and stores the new value in the pointee of the new_item
// then it updates the top index of the stack to point to the new_item
void	push(t_stack *s, int data)
{
	if (is_full(s))
	{
		ft_putstr_fd("Error\n", 2);
		return 1;
	}
	int	*new_item = malloc(sizeof(int));
	*new_item = data;
	s->top++;
	s->items[s->top] = new_item;
}

// Pop and delete an item from the stack
// if stack not empty, we get a pointer to the top item of the stack,
// stores the value of the item in a variable data, decrements the top index
// free the memory allocated for the pop_item and returns the value of the pop
// item to the caller
int		pop(t_stack *s)
{
	if (is_empty(s))
	{
		ft_putstr_fd("Error\n", 2);
		return 1;
	}
	int	data;
	int	*pop_item = s->items[s->top];
	data = *pop_item;
	s->top--;
	free(pop_item);
	return data;
}

// move the top element from stack a to the top of stack b
// use the combination of pop and push functions
// for pb, we make pop a, then push b
// for pa, we make pop b, then push a
void	push_b(t_stack *a, t_stack *b)
{
	if (is_empty(a))
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	int	data;

	write(1, "pb\n", 3);
	data = pop(a);
	push(b, data);
}

// move the top element from stack b to the top of stack a
void	push_a(t_stack *b, t_stack *a)
{
	if (is_empty(b))
	{
		ft_putstr_fd("Error\n", 2);;
		exit (1);
	}
	int	data;

	write(1, "pa\n", 3);
	data = pop(b);
	push(a, data);
}

// function to swap the two top elements of the stack
void	swap_a(t_stack *a)
{
	if (a->top < 1) // check if the is at least 2 values in the stack
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	write(1, "sa\n", 3);
	int	temp = a->items[a->top];
	a->items[a->top] = a->items[a->top-1]; // top-1 = 2e element
	a->items[a->top-1] = temp;
}

void	swap_b(t_stack *b)
{
	if (b->top < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	write(1, "sb\n", 3);
	int	temp = b->items[b->top];
	b->items[b->top] = b->items[b->top-1];
	b->items[b->top-1] = temp;
}

// top number goes to bottom
void	rotate_a(t_stack *a)
{
	if (a->top < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
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
void	rotate_b(t_stack *b)
{
	if (b->top < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
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
void	rev_rotate_a(t_stack *a)
{
	if (a->top < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
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

void	rev_rotate_b(t_stack *b)
{
	if (b->top < 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
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