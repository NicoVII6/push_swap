/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homemade_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:26:05 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:10:03 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int		three_numb_sort(t_stack *a)// checker parametres
{
	// faire une condition au cas ou les valeurs de la stack sont deja triees
	if ((a->items[a->top] > a->items[a->top-1) && (a->items[a->top-1] < a->items[a->top-2])
		&& (a->items[a->top-2] > a->items[a->top]))
	{
		swap_a(a);
		return 0; // means the swap was performed good
	}
	else if ((a->items[a->top] > a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		swap_a(a);
		rev_rotate_a(a);
		return 0;
	}
	else if ((a->items[a->top] > a->items[a->top-1]) && (a->items[a->top-1] < a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		rotate_a(a);
		return 0;
	}
	else if ((a->items[a->top] < a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] > a->items[a->top]))
	{
		swap_a(a);
		rotate_a(a);
		return 0;
	}
	else if ((a->items[a->top] < a->items[a->top-1]) && (a->items[a->top-1] > a->items[a->top-2])
		&& (a->items[a->top-2] < a->items[a->top]))
	{
		rev_rotate_a(a);
		return 0;
	}
	return (a);
}

int		check_the_min(t_stack *a)
{
	int	min;
	int	i;

	min = a->items[0]; // 1st value
	i = 1; // to start the comparison with the 2nd value
	while (i < a->top)
	{
		if (a->items[i] < min)
		{
			min = a->items[i];
		}
		i++;
	}
	return min;
}

int		four_numb_sort(t_stack *a)
{
	int	min;

	min = check_the_min(a);
	push_b(min, b);
	three_numb_sort(a);
	// faire un push_a pour remettre la valeur min en haut de pile a
}

int		five_numb_sort(t_stack *a)
{
	int	min;

	min = check_the_min(a);
	push_b(min, b); 
	four_numb_sort(a);
}

int		small_numb_sort(t_stack *a)
{
	if (a->top < 2) // returns if there are not at least 3 values in the stack
		return 1;
	else if (a->top == 2)
		three_numb_sort(a);
	else if (a->top == 3)
		four_numb_sort(a);
	else
		five_numb_sort(a);
}