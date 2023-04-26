/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utills3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/11 15:29:19 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:12:13 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

// utile pour faire la sortie d'erreur dans le programme
void	ft_putstr_fd(char *s, int fd)
{
	write (fd, s, ft_strlen(s));
}

// la fonction est bonne, mais elle doit etre adaptee au niveau
// des pointeurs
long int		*get_min_value(long int *arr, int size)
{
	int	min;
	int	i;

	if (size <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	min = arr[0];
	i = 1;
	while (i < size)
	{
		if (arr[i] < min)
			min = arr[i];
		i++;
	}
	return min;
}

// reflechir a comment utiliser la sorted_array du merge sort
// dans cette fonction. A t-on besoin d'une array temporaire ?
long int		index_association(long int *arr,long int *temp, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		temp[i] = get_min_value(arr, n);
	}
}