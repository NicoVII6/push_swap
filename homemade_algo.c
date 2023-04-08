/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   homemade_algo.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/07 16:26:05 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 19:00:13 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*three_numb_sort(t_dlist *a)
{
	if ((a->data > a->next->data) && (a->next->data >a->next->next->data))
	{
		//deja trie
		return 0;
	}
	else if ((a->data > a->next->data) && (a->next->data <a->next->next->data)
		&& (a->next->next->data > a->data))
	{
		swap_a(a);
		return 0; // means the swap was performed good
	}
	else if ((a->data > a->next->data) && (a->next->data >a->next->next->data)
		&& (a->next->next->data < a->data))
	{
		swap_a(a);
		reverse_rotate_a(a);
		return 0;
	}
	else if ((a->data > a->next->data) && (a->next->data <a->next->next->data)
		&& (a->next->next->data < a->data))
	{
		rotate_a(a);
		return 0;
	}
	else if ((a->data < a->next->data) && (a->next->data >a->next->next->data)
		&& (a->next->next->data > a->data))
	{
		swap_a(a);
		rotate_a(a);
		return 0;
	}
	else if ((a->data < a->next->data) && (a->next->data >a->next->next->data)
		&& (a->next->next->data < a->data))
	{
		reverse_rotate_a(a);
		return 0;
	}
	return (a);
}

t_dlist		*four_numb_sort(t_dlist *a, t_dlist *b)
{
	int	min;

	min = get_min_value(a);
	push_b(&min, &b);
	three_numb_sort(a);
	push_a(&min, &a);
	return (a);
}

t_dlist		*five_numb_sort(t_dlist *a, t_dlist *b)
{
	int	min;

	min = get_min_value(a);
	push_b(&min, &b); 
	four_numb_sort(a, b);
	push_a(&min, &a);
	return (a);
}

t_dlist		*small_numb_sort(t_dlist *a, t_dlist *b)
{
	if (list_size(a) == 2)
	{
		if (a < a->next)
			swap_a(a);
	}
	else if (list_size(a) == 3)
		three_numb_sort(a);
	else if (list_size(a) == 4)
		four_numb_sort(a, b);
	else
		five_numb_sort(a, b);
	return (a);
}