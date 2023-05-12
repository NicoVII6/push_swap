/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:06:42 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/11 19:07:52 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get to a particular index in the list according to a particular value
int		get_index_from_value(t_stack **stack, int num)
{
	int		i;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while ((*stack)->next != NULL)
	{
		if ((*stack)->data == num)
		{
			*stack = temp; // remet la stack sur le top avant de retourner l'index
			return (i);
		}
		(*stack) = (*stack)->next;
		i++;
	}
	*stack = temp; // remet la stack sur le top avant return si rien trouvé
	return(-1); // index non trouvé
}

// return the data contains in an particular index in the list
int		get_data_from_index(t_stack **stack, int index)
{
	int		i;
	int		content;
	t_stack	*temp;

	temp = *stack;
	i = 0;
	while (i < index)
	{
		*stack = (*stack)->next;
		i++;
	}
	content = (*stack)->data;
	*stack = temp; // revient au top de la stack
	return (content);
}