/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 17:44:54 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_lists	*stacks;

	stacks = malloc(2 * sizeof(t_dlist));
	if (argc < 2)
		return 1; // ne rien imprimer et rendre l'invite de commande
	// initialisation des listes a et b
	stacks->a = NULL;
	stacks->b = NULL;
	// signifie que inputs sont situes entre double quote, donc split necessaire
	// et on le fait sur argv[1], car argv[0] est pour l'executable
	if (argc == 2)
		argv = ft_split((const	char *) argv[1], ' ');
	stacks = parse_args(stacks, argc, argv); // fonction retourne un pointeur vers la stacks
	if (argc >= 3 && argc <= 6)
		small_numb_sort(stacks->a, stacks->b);
	else
	{
		stacks = normalize(stacks);
		stacks->a = decimal_to_binary(stacks->a);
		radix_sort(stacks->a, stacks->b);
		//radix_sort(a, b); 
	}
	if (list_size(stacks->a) > 0)
		clear_list(stacks->a);
	if (list_size(stacks->b) > 0)
		clear_list(stacks->b);
	free(stacks);
	return (0);
}