/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/26 17:55:24 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	

	if (argc < 2)
		return 1; // ne rien imprimer et rendre l'invite de commande
	stack_a = NULL;
	stack_b = NULL;
	// signifie que inputs sont situes entre double quote, donc split necessaire
	// et on le fait sur argv[1], car argv[0] est pour l'executable
	if (argc == 2)
	{
		argv = ft_split((const	char *) argv[1], ' ');
		argc = 0;
		while (argv[argc])
			argc++;

	}
	else
	{
		argv++;
		argc--;
	}
	if(parse_args(&stack_a, argc, argv) == 1)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	db_show_stack(&stack_a, &stack_b);
	normalize(stack_a);
	db_show_stack(&stack_a, &stack_b);
	algo_choice(&stack_a, &stack_b, argc);
	if (ft_stksize(stack_a) > 0)
		ft_stkclear(&stack_a); // free tous les elements de la stack
	if (ft_stksize(stack_b) > 0)
		ft_stkclear(&stack_b);
	free(stack_a); // free la stack
	free(stack_b);
	return (0);
}