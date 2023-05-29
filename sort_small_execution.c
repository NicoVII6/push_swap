/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_execution.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:13:18 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/23 16:16:25 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_move(t_stack **stack)
{
	swap_a(stack);
	reverse_rotate_a(stack);
}

void	execute_move2(t_stack **stack)
{
	swap_a(stack);
	rotate_a(stack);
}

void	execute_move3(t_stack **stack_a)
{
	swap_a(stack_a);
	rotate_a(stack_a);
	swap_a(stack_a);
	reverse_rotate_a(stack_a);
}

void	execute_move4(t_stack **stack_a)
{
	reverse_rotate_a(stack_a);
	swap_a(stack_a);
	rotate_a(stack_a);
	rotate_a(stack_a);
}
