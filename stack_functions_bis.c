/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_functions_bis.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:05:13 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/23 14:58:28 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// retourne 'msg erreur' si stack est vide
int	ft_stkisempty(t_stack *stack)
{
	return (!stack);
}

// retourne contenu du current node de la stack
int	ft_stkpeek(t_stack *stack)
{
	if (ft_stkisempty(stack))
		return (0);
	return (stack->data);
}

// return stack size
int	ft_stksize(t_stack *stack)
{
	int		size;

	size = 0;
	while (stack)
	{
		size++;
		stack = stack->next;
	}
	return (size);
}
