/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 13:14:40 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/24 14:50:23 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "push_swap.h"

// function which prints a list of values
void	print_list(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while ((*stack)->next != NULL)
	{
		printf("%d\n", (*stack)->data);
		(*stack) = (*stack)->next;
	}
	*stack = tmp; // revient au top de la stack
}

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
/*
void    display_lst(t_dlist **ptr_to_head, char *name)
{
    t_dlist    *current_node;
    int        count;

    current_node = *ptr_to_head;
    count = 0;
    printf("\n%s :\n", name);
    if (*ptr_to_head != NULL)
    {
        while (current_node->prev != NULL)
        {
            printf("Index = %d : ", count);
            display_node(current_node);
            current_node = current_node->prev;
            count++;
        }
        printf("Index = %d : ", count);
        display_node(current_node);
    }
    else
        printf("The stack is empty.\n");
    printf("\n");
}
*/

/*
void    display_node(t_dlist *lst)
{
    if (lst != NULL)
    {
        printf("[%p] {value = %ld | indice = %d | nx = %p}\n", lst,
            lst->nbr,
            lst->idx,
            lst->nx);
    }
}
*/