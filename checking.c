/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:14:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 15:25:12 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// print stacks
/*
void	db_show_stack(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	printf("--- Stack A ---\n");
	tmp = *stack_a;
	while (tmp)
	{
		printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	printf("--- Stack B ---\n");
	tmp = *stack_b;
	while (tmp)
	{
		printf("- %d\n", ft_stkpeek(tmp));
		tmp = tmp->next;
	}
	printf("\n");
	free(tmp);
}
*/