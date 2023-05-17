/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:10:46 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 18:00:45 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retourne un pointeur qui pointe sur valeur max
t_stack		*ptr_to_maximum(t_stack *stack)
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
	t_stack		*temp;
	t_stack		*min_ptr;
	long		min_value;

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
t_stack		*normalize(t_stack *stack_a)
{
	int		i;
	t_stack	*min;
	t_stack	*max;
	int		size;

	i = 0;
	size = ft_stksize(stack_a);
	// a chaque iteration de i, la fonction ptr_to_min va chercher la + petite valeur restante dans la liste a
	// une fois trouvee, on accede a la data qui est pointee par min et on la remplace par la valeur LONG_MAX -1 -i
	// Ainsi chaque fois que la valeur min est identifiee on la remplace par LONG_MAX -1 - la i-eme valeur min
	// BUT de l'operation : evacuer les min deja trouvees et continuer le processus.
	// a la fin de la premiere boucle while,
	// THE FIRST LOOP IS USED TO CLASSIFY VALUES FROM THE SMALLER TO THE GREATER
	if (!stack_a)
		exit (1);
	while (i < size)
	{
		min = ptr_to_minimum(stack_a);
		min->data = (INT_MAX - (1 + i));
		i++;
	}
	i = 0;
	// THE SECOND LOOP IS USED TO NOMALIZE THOSE VALUES FROM 0 TO SIZE
	// le max correspond au plus petit trouve ds boucle precedente
	while (i < size)
	{
		max = ptr_to_maximum(stack_a);
		max->data = i;
		//printf("stack index %d\n", max->data);
		i++;
	}
	return (stack_a);
}