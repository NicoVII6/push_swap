/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:19:07 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:11:26 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.H"

// mettre un pointeur sur la sorted array
// distribuer les index de la sorted_array sur l'array originale
// en utilisant la fonction get_min_value (utils3)
// commencer la distribution en cherchant la valeur la plus petite
// lui attribuer le nouvel index et changer cette valeur en long_max
// refaire la meme operation pour l'index suivant et une fois l'attribution
// faite, attribuer la longueur long_max - 1. continuer l'operation
// jusqu'a ce que toutes les valeurs soient indexees

// RETRAVAILLER LES FONCTIONS MERGE SORT, MERGE_RECURSIVE, GET_MIN_VALUE
// ET INDEX_ASSOCIATION POUR QUE LE PROCESS FONCTIONNE
long int		merge_recursive(t_stack *s, int low, int high)
{
	int	mid;

	if (low >= high)
		return;
	// signifie que la subdivision est finie
	mid = (low + high) / 2;
	// split the left and right sub-array recursively
	merge_recursive(arr, low, mid);
	merge_recursive(arr, mid + 1, high); // right portion starts with index mid + 1
	// merge the sub-arrays
	merge_sort(arr, low, mid, high);
}
// function returns a pointer to the sorted array
long int		*merge_sort(long int arr[], int low, int mid, int high)
{
	long int	left_size;
	int	right_size;
	int	i;
	int	j;
	int	k;
	long int	*temp_left;
	long int	*temp_right;
	long int	*sorted_arr;

	left_size = mid - low + 1;
	right_size = high - mid;
	temp_left = malloc(sizeof(long int) * left_size);
	temp_right = malloc(sizeof(long int) * right_size);
	sorted_arr = malloc((left_size + right_size) * sizeof(long int));
	// copy data into temp left array
	i = 0;
	while (i < left_size)
	{
		temp_left[i] = sorted_arr[low + i];
		i++;
	}
	// copy data into temp right array
	i = 0;
	while (i < right_size)
	{
		temp_left[i] = sorted_arr[mid + 1 + i];
		i++;
	}
	// now we'll merge.  we have 3 counting variables.
	// k will be used as the index of array which is sorted
	// each time in the loop, we are gonna find the next value in k index from
	// temp_left or temp_right
	// i is gonna be the index for the temp_left array and j the temp_right one
	// i or j will be incremente only if we use the next element from it
	i = 0;
	j = 0;
	k = low;
	// merge into arr[k] until one of the left or right temp array is empty
	while (i < left_size && j < right_size)
	{
		if(temp_left[i] < temp_right[j])
		{
			sorted_arr[k] = temp_left[i];
			i++;
		}
		else
		{
			sorted_arr[k] = temp_right[j];
			j++;
		}
		k++;
	}
	// copy the remaining elements of temp_left (temp_right is empty)
	while (i < left_size)
	{
		sorted_arr[k] = temp_left[i];
		i++;
		k++;
	}
	// copy the remaining elements of temp_right
	while (j < right_size)
	{
		sorted_arr[k] = temp_right[j];
		j++;
		k++;
	}
	free(temp_left);
	free(temp_right);
	return (sorted_arr);
}
