/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 15:30:38 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 15:18:04 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	fill_array(int *arr, char **argv)
{
	int	i;

	i = 0;
	while (argv[i])
	{
		if (check_str_figures(argv[i]) == 0)
		{
			if (ft_atol(argv[i]) == 0)
				arr[i] = ft_atoi(argv[i]);
			else
				return (1);
		}
		else
			return (1);
		i++;
	}
	return (0);
}

int	validate_array(int *arr, int argc)
{
	if (check_duplicate(arr, argc) == 0)
		return (0);
	else
		return (1);
}

void	reverse_push_stack(t_stack **stack, int *arr, int argc)
{
	int	i;

	i = argc - 1;
	while (i >= 0)
	{
		ft_stkpush(stack, arr[i]);
		i--;
	}
}

int	parse_args(t_stack **stack_a, int argc, char *argv[])
{
	int	*arr;

	arr = (int *)malloc(sizeof(int) * argc);
	if (arr == NULL)
		return (1);
	if (fill_array(arr, argv) == 1)
	{
		free(arr);
		return (1);
	}
	if (validate_array(arr, argc) == 1)
	{
		free(arr);
		return (1);
	}
	reverse_push_stack(stack_a, arr, argc);
	free(arr);
	return (0);
}
