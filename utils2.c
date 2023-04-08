/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 14:28:52 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 17:24:42 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// utiliser long pour ensuite comparer ac int min et int max
long	ft_atoi(const char *str)
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
		ft_putstr_fd("Error\n", 2);
		exit (1);
	}
	else
		return (nb * sign);
}

int	list_size(t_dlist *a)
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

int	get_min_value(t_dlist *a)
{
	t_dlist	*temp;
	int		min;

	temp = a;
	min = a->data;
	while (temp)
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