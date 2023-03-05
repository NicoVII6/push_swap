/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:45:24 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/05 17:33:37 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(int *a, int n)
{
	stack	b;
	int	i;
	int	j;
	int	k;

	initialize_stack(&b);
	get_max_number(a); //  trouver la valeur max en binaire pour le radix
	i = 0;
	j = 0;
	while (max >> i > 0)
	{
		while (j < n)
		{
			// if the i-th bit from the right is 0, push to stack b
			if ((a[j] >> i) & 1 == 0)
				push(&b, a[j]);
			// otherwise do nothing
		}
		k = 0;
		// move the items from stach b to stack a
		while (!is_empty(&b))
		{
			a[k] = pob(&b);
			k++;
		}
	}
}