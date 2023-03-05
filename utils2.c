/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:52 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/05 17:33:25 by ndecotti         ###   ########.fr       */
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

// a retravailler, faire a l'aide d'une recursion
int		binary_base(int arr[index], int n)
{
	int	i;
	int	binary_ind;
	int	base;

	i = 0;
	binary_ind = 0;
	base = 1;
	while (i <= n)
	{
		while (index > 0)
		{
			binary_ind += (index % 2) * base;
			index /= 2;
			base *= 10;
		}
		printf("%d", binary_ind);
	}
	printf("\n");
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