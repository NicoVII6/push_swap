/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 13:10:08 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 17:25:44 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_dlist		*radix_sort(t_dlist *a, t_dlist *b)
{
	int		i;
	int		max;

	max = get_max_value(a); // trouver la valeur max en binaire pour le radix
	//size = list_size(a);

	i = 0;
	// tant que le nb max est a une unit superieure a 0, alors le tri continue
	while ((max >> i) > 0)
	{
		while (a)
		{
			// if the i-th bit from the right is 0, push to stack b
			if (((a->data >> i) & 1) == 0)
				push_b(a, &b);
			else
				rotate_a(a);
			a = a->next;
		}
		// move the items from stach b to stack a
		while (b)
		{
			push_a(b, &a); // revoir parametres
			b = b->next;
		}
		i++;
	}
	return (a);
}