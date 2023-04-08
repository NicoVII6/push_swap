/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:30:38 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 18:10:21 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// function which parse arguments into stack a
// returns a pointer to the stack
t_lists	*parse_args(t_lists *stacks, int argc, char *argv[])
{
	int		i;
	long	temp;

	i = 1;
	// means that if we have a string which contains all the values
	// argv begins with argv[0] elsewhere it starts with argv[i]
	if (argc == 2)
		i = 0;
	// loop continues until no arguments left to parse
	while (argv[i])
	{
		if (!check_str_figures(argv[i]))
			temp = ft_atoi(argv[i]);
		check_duplicate(stacks->a, temp);
		// si la stack a est vide, on créée un nouveau node en appelant new_list function
		if (!stacks->a)
			stacks->a = new_list(temp);
		// sinon on ajoute l'argument à la suite (par le haut) dans la liste en appelant
		// la fonction add_to_head ac pour parametres l'acces a l'adresse 
		// d'un element de la liste a et la fonction new_list qui cree un nouveau node et
		// ajoute la data correspondante apres avoir utilise ft_atoi et permet ainsi d'ajouter
		// ce nouveau node a la liste principale de add_to_head
		else
			add_to_head(&stacks->a, new_list(ft_atoi(argv[i])));
		i++;
	}
	return (stacks);
}