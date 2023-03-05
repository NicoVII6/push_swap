/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/05 17:33:10 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


int	main(int argc, char *argv[])
{
	if (argc < 2)
	{
		// ne rien imprimer et rendre l'invite de commande
	}

	if (argc == 2)
	{
		// split ? puis if a > b, swap a, sinon deja sorted
	}

	if (argc <= 6)
	{
		// split
		//home made algorithm
	}

	// faire un split avec un char ** ou char * pour les arguments

	// int	input[MAX_INPUT_SIZE];
	// int	input_size;
	int	i;
	int	n;
	// input_size = 0;
	int	arr[n];
	int	temp[n];

	n = argc - 1;
	i = 1;
	while (i <= n)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		if (arr[i - 1] < INT_MIN || arr[i - 1] > INT_MAX)
			return ; // error
		i++;
		//input[input_size++] = value;
	}

	// copy the input array of integers and sort this copy
	// int	copy[MAX_INPUT_SIZE];
	// int	copy_size = input_size;
	// i = 0;
	// while (i < input_size)
	// {
	//	copy[i] = input[i];
	//	i++;
	// }
	// sort_array(copy, copy_size);

	merge_recursive(arr, temp, 0, n - 1); // n - 1 a partir index 0 car n elements a partir argv[1]
	
	// assigner nouvel index au tableau original pour que le radix de ces indexs soit synchroniser
	// avec la liste originale et que les commandes effectuees lors du radix fassent directement
	// bouger les valeurs de depart ??
	// A retravailler
	
	binary_base(arr, n - 1); // fonction qui convertit index en binaire

	// Replace each element of input with its index in the sorted copy

	/*i = 0;
	int	index;
	while (i < input_size)
	{
		index = 0;
		while (index < copy_size && copy[index] < input[i])
		{
			intput[i] = index;
			i++;
			index++;
		}
	}*/

	radix_sort();
}