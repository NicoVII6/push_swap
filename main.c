/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:09:54 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		return 1; // ne rien imprimer et rendre l'invite de commande
	}
	// signifie que inputs sont situes entre double quote, donc split necessaire
	// et on le fait sur argv[1], car argv[0] est pour l'executable
	if (argc == 2)
	{
		ft_split((const	char *) argv[1], ' ');
	}
	int	n;
	int	i;
	long int	*arr;
	// faire un malloc pour long int arr
	if (argc == 3)
	{
		// mini fonction
	}
	if (argc > 3 && argc <= 6)
	{
	//	homemade algo
	}
	n = argc - 1;
	i = 1;
	while (i < n)
	{
		check_str_numb(argv[i]);
		arr[i - 1] = ft_atoi(argv[i]);
		i++;
	}
	check_duplicates(arr, n);
	int	*temp = merge_recursive(arr, 0, n - 1); // n - 1 a partir index 0 car n elements a partir argv[1]
	index_association(arr, temp, n);
	decimal_to_binary(arr, n - 1);

	// Replace each element of input with its index in the sorted copy
	radix_sort();
}

// function to check if there are duplicates
// we have a nested loop to compare each value in the array with all other value
// we start with the value in arr[0] and compare with all others arr[j] starting with j = i + 1;
// when we finish with all the value of j; we increment i and start again the operation from j = i + 1
// to j = n - 1 again, and we continue this way until all values have been checked
int	check_duplicates(long int *arr, int n)
{
	int	i;
	int	j;

	i = 0;
	while (i < n)
	{
		j = i + 1;
		while (j < n)
		{
			if (arr[i] == arr[j])
			{
				ft_putstr_fd("Error\n", 2);
				exit (1);
			}
			j++;
		}
		i++;
	}
	return 0;
}

int	check_str_numb(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
		{
			ft_putstr_fd("Error\n", 2);
			exit (1);
		}
		else
			i++;
	}
	return 0;
}