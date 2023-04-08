/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands_final.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 15:18:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 16:37:45 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*swap_a(t_dlist *a)
{
	t_dlist	*temp;
	t_dlist	*temp2;

	if (a == NULL || a->next == NULL)
		return (NULL);
	temp = a;
	temp2 = a->next;
	a = temp2;
	a->next = temp;
	write(1,"sa\n", 3);
	return (a);
}

t_dlist		*swap_b(t_dlist *b)
{
	t_dlist	*temp;
	t_dlist	*temp2;

	if (b == NULL || b->next == NULL)
		return (NULL);
	temp = b;
	temp2 = b->next;
	b = temp2;
	b->next = temp;
	write(1, "sb\n", 3);
	return (b);
}

t_dlist		*rotate_a(t_dlist *a)
{
	t_dlist	*first;
	t_dlist	*second;

	if(a == NULL || a->next == NULL)
		return (NULL);
	first = go_to_head(a);
	second = first->prev;
	second->next = NULL;
	first->prev = NULL;
	first->next = go_to_tail(a);
	first->next->prev = first;
	a->next = first;
	write(1, "ra\n", 3);
	return (a);
}

t_dlist		*rotate_b(t_dlist *b)
{
	t_dlist	*first;
	t_dlist	*second;

	if(b == NULL || b->next == NULL)
		return (NULL);
	first = go_to_head(b);
	second = first->prev;
	second->next = NULL; // second devient head (son next pointe sur NULL)
	first->prev = NULL; // pointe sur NULL puisque tail
	first->next = go_to_tail(b); // pointeur next de la new tail pointe sur le tail original
	first->next->prev = first; // update the previous pointer of the original tail
						// before the rotation, original tail points to the old head of the list
						// after the rotation the old head becomes the new tail and its previous pointer
						// points to NULL. we need to update the previous pointer of the original tail
						// to point to the new tail (which is now the old head) to ensure the list remains circular
	b->next = first;
	write(1, "rb\n", 3);
	return (b);
}

// REVOIR EN UTILISANT FUNCTION ADD TO HEAD
t_dlist		*reverse_rotate_a(t_dlist *a)
{
	t_dlist	*last;
	t_dlist	*second_last;

	if (a == NULL || a->next == NULL)
		return (NULL);
	last = go_to_tail(a);
	second_last = last->next;
	add_to_head(&a, last);
	second_last->prev = last; // connecte new tail ac new head
	write(1, "rra\n", 4);
	return (a);
}

// REVOIR EN DETAILS
t_dlist		*reverse_rotate_b(t_dlist *b)
{
	t_dlist	*last;
	t_dlist	*second_last;

	if (b == NULL || b->next == NULL)
		return (NULL);
	last = go_to_tail(b);
	second_last = last->next;
	add_to_head(&b, last);
	second_last->prev = last; // connecte new tail ac new head
	write(1, "rrb\n", 4);
	return (b);
}

t_dlist		*push_b(t_dlist *a, t_dlist **b)
{
	t_dlist	*new;
	t_dlist *second;

	new = go_to_head(a); // aller 1er element liste a
	second = new->prev; // second noeud de a
	second->next = NULL; // initialise second pour etre head de liste a
	second->prev = new->prev->prev; // connecte nouveau head ac second node
	new = malloc(sizeof(t_dlist));
	if (!new)
		return NULL;
	add_to_head(b, new); // go the head of b and connect new from a to the top of b list
	clear_list(a); // clear the head node a moved to b
	write(1, "pb\n", 3);
	return (a);
}

t_dlist		*push_a(t_dlist *b, t_dlist **a)
{
	t_dlist	*new;
	t_dlist	*second;

	new = go_to_head(b);
	second = new->prev;
	second->next = NULL;
	second->prev = new->prev->prev;
	new = malloc(sizeof(t_dlist));
	if (!new)
		return NULL;
	add_to_head(a, new);
	clear_list(b);
	write(1, "pa\n", 3);
	return (b);
}