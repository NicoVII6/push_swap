/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:29:19 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 18:14:00 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utile pour faire la sortie d'erreur dans le programme
void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

void	ft_error(t_stack **stack_a, t_stack **stack_b)
{
	write(2, "Error\n", 6);
	ft_stkclear(stack_a);
	ft_stkclear(stack_b);
	exit(1);
}

// fonction qui check si stack est triee
// si deja triee, elle retourne 1, sinon 0
// dans les deux cas, on se remet sur le top de la stack avant return
int		is_sorted(t_stack **stack)
{
	t_stack	*temp;

	temp = *stack;
	while (*stack && (*stack)->next)
	{
		if ((*stack)->data > (*stack)->next->data)
		{
			*stack = temp;
			return (0);
		}
		*stack = (*stack)->next;
	}
	*stack = temp;
	return (1);
}
/*
void	free_arg(int argc, char **argv)
{
	int		i;

	i = 0;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}
*/