/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:52 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:08 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// adapter et changer argument de la fonction
int	ft_atoi(const char *str)
{
	int	i;
	int	nb;
	int	sign;

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

// get the digit in the specified place value
// compter le nombre de digits d'un nombre
int	get_number_digits(int value)
{
	int	digits = 0;
	while (value > 0)
	{
		value /= 10;
		digits++;
	}
	return digits;
}

int	get_max_value(int arr[], int size)
{
	int	max;
	int	i;

	if (size <= 0)
		return ; // any appropriate value indicating an error
	max = arr[0];
	i = 1;
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
int		**decimal_to_binary(int arr[], int len)
{
	int	i;
	int	index;
	int	decimal;
	int	**binary_arr = malloc(sizeof(int*) * len); // to store len pointer to integers to arr[]

	i = 0;
	index = 0;
	decimal = i;
	while (i < len)
	{
		binary_arr[i] = malloc(sizeof(int) * 32); // to store 32-bit binary integers
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
	int	temp;

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