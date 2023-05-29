/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:10:46 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 15:00:22 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retourne un pointeur qui pointe sur valeur max
t_stack	*ptr_to_maximum(t_stack *stack)
{
	t_stack		*temp;
	t_stack		*max_ptr;
	long		max_value;

	temp = stack;
	max_value = (stack)->data;
	max_ptr = temp;
	while (temp)
	{
		if (temp->data > max_value)
		{
			max_ptr = temp;
			max_value = temp->data;
		}
		temp = temp->next;
	}
	return (max_ptr);
}

// retourne un pointeur qui pointe sur la valeur min
t_stack	*ptr_to_minimum(t_stack *stack)
{
<<<<<<< HEAD
	t_stack	*temp;
	t_stack	*min_ptr;
	long	min_value;
=======
	t_stack		*temp;
	t_stack		*min_ptr;
	long		min_value;
>>>>>>> 52b0d4c560895de2075f49c6be2dd9d0b01693df

	temp = stack;
	min_value = stack->data;
	min_ptr = temp;
	while (temp)
	{
		if (temp->data < min_value)
		{
			min_ptr = temp;
			min_value = temp->data;
		}
		temp = temp->next;
	}
	return (min_ptr);
}

// Function which take the list a as parameter
// it first classifies values from the smaller to the greater
// and then normalize those value from 0 to N(size)
// then returns a pointer to the nomalize list a
t_stack	*normalize(t_stack *stack_a)
{
	int		i;
	t_stack	*min;
	t_stack	*max;
	int		size;

	i = 0;
	size = ft_stksize(stack_a);
	if (!stack_a)
		exit (1);
	while (i < size)
	{
		min = ptr_to_minimum(stack_a);
<<<<<<< HEAD
		min->data = (LONG_MAX - (1 + i));
=======
		min->data = (INT_MAX - (1 + i));
>>>>>>> 52b0d4c560895de2075f49c6be2dd9d0b01693df
		i++;
	}
	i = 0;
	while (i < size)
	{
		max = ptr_to_maximum(stack_a);
		max->data = i;
		i++;
	}
	return (stack_a);
}
