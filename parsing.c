/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:30:38 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/26 17:55:44 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atol(const char *str)
{
	int		i;
	int		sign;
	long	nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (nb < INT_MIN || nb > INT_MAX)
	{
		return (1);
	}
	return (0);
}

int	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	int		nb;

	i = 0;
	nb = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\f' || str[i] == '\r')
		i++;
	if (str[i] == '-')
	{
		sign *= (-1);
		i++;
	}
	else if (str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	return (nb * sign);
}

// function that checks if all arguments are figures
// retourne erreur si figure = --16 par exemple
int	check_str_figures(char *str)
{
	int	i;

	i = 0;
	if (str[i] == 45)
		i++;
	while (str[i])
	{
		if (str[i] < 48 || str[i] > 57)
		{
			return (1);
		}
		else
			i++;
	}
	return 0;
}

int	check_duplicate(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] == arr[j])
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return 0;
}

// compare data avec les autres contenus de la liste pour voir si doublon
/*int	check_duplicate(t_stack *stack_a, int num)
{
	t_stack	*tmp;

	tmp = stack_a;
	while (tmp)
	{
		if (tmp->data == num)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return 0;
}*/
// ici on circule ds la stack avec tmp donc qd on retourne, la stack est
// au meme endroit qu'au moment du call de la fonction

// function which parse arguments into stack a
// returns a pointer to the stack
// LA FONCTION MARCHE CORRECTEMENT, VOIR AC LE PRINT_LIST A LA FIN
int parse_args(t_stack **stack_a, int argc, char *argv[])
{
	int		i;
	int		*arr;

	// means that if we have a string which contains all the values
	// argv begins with argv[0] elsewhere it starts with argv[i]
	arr = (int *)malloc(sizeof(int) * argc);
	i = 0;
	// loop continues until no arguments left to parse
	// a chaque iteration, on ajoute la variable temp dans la stack de sorte
	// que a chaque appel de la fonction check_duplicate, la liste contient
	// un element supplementaire.
	// verifier qu'a chaque iteration, la variable temp est bien actualisee
	// du nouveau int recu par la fonction atoi.
	while (argv[i])
	{
		if (check_str_figures(argv[i]) == 0)
		{
			if(!ft_atol(argv[i]))
			{
				arr[i] = ft_atoi(argv[i]);
			}
		}
		else
			return (1);
		i++;
		// si la stack a est vide, on créée un nouveau node en appelant new_list function
	}
	if(check_duplicate(arr, argc) != 0)
	{
		return (1);
	}

	// verifier si le tableau ne contient pas de doublons
	i = argc - 1;
	while (i >= 0)
	{
		ft_stkpush(stack_a, arr[i]);
		i--;
	}
	free(arr);
	return (0);
}