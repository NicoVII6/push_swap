/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:29:19 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 17:41:59 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utile pour faire la sortie d'erreur dans le programme
void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

// function that checks if all arguments are figures
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
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		else
			i++;
	}
	return 0;
}

// prends en parametres un pointeur sur la liste a et la data correspondante
// on distribue chaque argument recu en 
// compare cette data avec les autres de la liste pour voir si doublon
int	check_duplicate(t_dlist *a, int data)
{
	t_dlist	*tmp;

	tmp = a;
	while (tmp)
	{
		if (tmp->data == data)
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_dlist	*decimal_to_binary(t_dlist *a) // ou t_lists *stacks ??
{
	t_dlist	*temp;
	int		decimal_val;
	int		binary_val;
	
	temp = a;
	while (temp)
	{
		decimal_val = temp->data;
		binary_val = dec_to_bin_convert(temp->data);
		temp->data = binary_val;
		temp = temp->next;
	}
	return (a);
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