/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:52 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:10:59 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utiliser long int pour ensuite comparer ac int min et int max
// verifier que le tableau ait bien ete converti en long int partout
long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long int	nb;

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
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	else
		return (nb * sign);
}

// get the digit in the specified place value
// compter le nombre de digits d'un nombre
int	get_number_digits(long int value)
{
	int	digits = 0;
	while (value > 0)
	{
		value /= 10;
		digits++;
	}
	return digits;
}

long int	get_max_value(long int arr[], int size)
{
	long int	max;
	int	i;

	if (size <= 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	max = arr[0];
	i = 1; // index pour la 1ere comparaison ac index 0
	while (i < size)
	{
		if (arr[i] > max)
		{
			max = arr[i];
		}
		i++;
	}
	return max;
}

// the function returns a double pointer because it returns a pointer to an array (binary_arr)
// which itself points to the decimal array[];
long int		**decimal_to_binary(long int arr[], int len)
{
	int	i;
	int	index;
	long int	decimal;
	long int	**binary_arr = malloc(sizeof(long int *) * len); // to store len pointer to integers to the arr[]

	i = 0;
	index = 0;
	decimal = i;
	while (i < len)
	{
		binary_arr[i] = malloc(sizeof(long int));
		while (decimal > 0)
		{
			binary_arr[i][index] = decimal % 2;
			decimal = decimal / 2;
			index++;
		}
		i++;
	}
	// Reverse the order of the bits in binary_arr[i] to display the binary value correctly
	int	start;
	int	end;
	long int	temp;

	start = 0;
	end = index - 1;
	while (start < end)
	{
		temp = binary_arr[i][start];
		binary_arr[i][start] = binary_arr[i][end];
		binary_arr[i][end] = temp;
		start++;
		end--;
	}
	return binary_arr;
}

/* la fonction duplique la string src vers une string dst nouvellement créée et retourne
un pointeur sur la string dst si la duplication réussie, sinon elle retourne la valeur NULL */

char	*ft_strdup(const char *src)
{
	char	*dst;
	int		i;
	int		len;

	len = ft_strlen((char *)src);
	dst = (char *) malloc (sizeof(char) * len + 1);
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}