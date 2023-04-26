/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:52 by ndecotti          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/04/08 17:24:42 by ndecotti         ###   ########.fr       */
=======
/*   Updated: 2023/03/12 19:10:59 by ndecotti         ###   ########.fr       */
>>>>>>> 0efcfd16aeb7877506aba8592fd51aee872c709b
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

<<<<<<< HEAD
// utiliser long pour ensuite comparer ac int min et int max
long	ft_atoi(const char *str)
{
	int		i;
	int		sign;
	long	nb;
=======
// utiliser long int pour ensuite comparer ac int min et int max
// verifier que le tableau ait bien ete converti en long int partout
long int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	long int	nb;
>>>>>>> 0efcfd16aeb7877506aba8592fd51aee872c709b

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

<<<<<<< HEAD
int	list_size(t_dlist *a)
=======
// get the digit in the specified place value
// compter le nombre de digits d'un nombre
int	get_number_digits(long int value)
>>>>>>> 0efcfd16aeb7877506aba8592fd51aee872c709b
{
	t_dlist	*temp;
	int		count;
	
	temp = a;
	count = 0;
	while (temp)
	{
		count++;
		temp = temp->next;
	}
	return (count);
}

<<<<<<< HEAD
int	get_min_value(t_dlist *a)
{
	t_dlist	*temp;
	int		min;

	temp = a;
	min = a->data;
	while (temp)
=======
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
>>>>>>> 0efcfd16aeb7877506aba8592fd51aee872c709b
	{
		if (temp->data < min)
			min = temp->data;
		temp = temp->next;
	}
	return min;
}

int	get_max_value(t_dlist *a)
{
	t_dlist	*temp;
	int		max;

	temp = a;
	max = a->data;
	while (temp)
	{
		if (temp->data > max)
			max = temp->data;
		temp = temp->next;
	}
	return max;
}

<<<<<<< HEAD
// retourne un pointeur qui pointe sur valeur max
t_dlist	*ptr_to_maximum(t_dlist *a)
{
	t_dlist	*temp;
	t_dlist	*max_ptr;
	int	max_value;

	temp = a;
	max_ptr = temp;
	max_value = temp->data;
	while (temp)
	{
		if (temp->data > max_value)
		{
			max_value = temp->data;
			max_ptr = temp;
		}
		temp = temp->next;
	}
	return (max_ptr);
=======
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
>>>>>>> 0efcfd16aeb7877506aba8592fd51aee872c709b
}

// retourne un pointeur qui pointe sur la valeur min
t_dlist	*ptr_to_minimum(t_dlist *a)
{
	t_dlist	*temp;
	t_dlist	*min_ptr;
	int	min_value;

	temp = a;
	min_ptr = temp;
	min_value = temp->data;
	while (temp)
	{
		if (temp->data < min_value)
		{
			min_value = temp->data;
			min_ptr = temp;
		}
		temp = temp->next;
	}
	return (min_ptr);
}