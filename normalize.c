/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 19:10:46 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 17:08:44 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// Function which take the list a as parameter
// it first classifies values from the smaller to the greater
// and then normalize those value from 0 to N(size)
// then returns a pointer to the nomalize list a
t_lists	*normalize(t_lists *stacks)
{
	int		i;
	int		size;
	t_dlist	*min;
	t_dlist	*max;

	i = 0;
	// sets the value of size to the number of elements in the linked list by calling the list_size function
	size = list_size(stacks->a); // stacks->a pointe directement sur le top de la liste
	// a chaque iteration de i, la fonction ptr_to_min va chercher la + petite valeur restante dans la liste a
	// une fois trouvee, on accede a la data qui est pointee par min et on la remplace par la valeur LONG_MAX -1 -i
	// Ainsi chaque fois que la valeur min est identifiee on la remplace par LONG_MAX -1 - la i-eme valeur min
	// BUT de l'operation : evacuer les min deja trouvees et continuer le processus.
	// a la fin de la premiere boucle while,
	// THE FIRST LOOP IS USED TO CLASSIFY VALUES FROM THE SMALLER TO THE GREATER
	while (i < size)
	{
		min = ptr_to_minimum(stacks->a);
		min->data = LONG_MAX - (1 + i);
		i++;
	}
	i = 0;
	// THE SECOND LOOP IS USED TO NOMALIZE THOSE VALUES FROM 0 TO SIZE
	while (i < size)
	{
		max = ptr_to_maximum(stacks->a);
		max->data = i;
		i++;
	}
	return (stacks);
}