/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:29:19 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/24 18:21:16 by ndecotti         ###   ########.fr       */
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

t_stack	*decimal_to_binary(t_stack **stack_a)
{
	t_stack	*temp;
	int		decimal_val;
	int		binary_val;
	
	temp = *stack_a;
	while ((*stack_a)->next)
	{
		decimal_val = (*stack_a)->data;
		binary_val = dec_to_bin_convert(decimal_val);
		(*stack_a)->data = binary_val; // remplace valeur decimale par valeur binaire ds noeud
		(*stack_a) = (*stack_a)->next;
	}
	*stack_a = temp; // on revient au top de la stack avant de la retourner
	return (*stack_a);
}

int		dec_to_bin_convert(int decimal_val)
{
	int	quotient;
	int	remainder;
	int	binary_val;
	int	unit;

	quotient = decimal_val;
	binary_val = 0;
	unit = 1;
	while (quotient != 0)
	{
		remainder = decimal_val % 2;
		quotient = decimal_val / 2;
		binary_val += remainder * unit;
		unit *= 10;
	}
	return (binary_val);
}