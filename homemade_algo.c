/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homemade_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:26:05 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:10 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define STACK_SIZE 10000

typedef struct stack {
	int	top;
	int	items[STACK_SIZE];
} stack;

int		three_numb_sort(stack *a)// checker parametres
{
	// faire une condition au cas ou les valeurs de la stack sont deja triees
	if ((a->items[a->top] > a->items[a->top-1) && (a->items[a->top-1] < a->items[a->top-2])
		&& (a->items[a->top-2] > a->items[a->top]))
	{
		swap_a(a);
		return 1; // means the swap was performed good
	}
	else if ((a->items[a->top] > a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		swap_a(a);
		rev_rotate_a(a);
		return 1;
	}
	else if ((a->items[a->top] > a->items[a->top-1]) && (a->items[a->top-1] < a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		rotate_a(a);
		return 1;
	}
	else if ((a->items[a->top] < a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] > a->items[a->top]))
	{
		swap_a(a);
		rotate_a(a);
		return 1;
	}
	else if ((a->items[a->top] < a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		rev_rotate_a(a);
		return 1;
	}
	return 0;
}

int		four_numb_sort(stack *a)
{
	stack *b = 0;

	push_b(a->items[a->top], b);
	three_numb_sort(a);

}

int		five_numb_sort(stack *a)
{
	stack *b = 0;

	push_b(a->items[a->top], b);
	push_b(a->items[a->top], b); // la stack actualisee ne compte plus que 4 valeurs
	three_numb_sort(a);
}

int		small_numb_sort(stack *a)
{
	if (a->top < 2) // returns if there are not at least 3 values in the stack
		return 0;
	else if (a->top == 2)
		three_numb_sort(a);
	else if (a->top == 3)
		four_numb_sort(a);
	else
		five_numb_sort(a);
}