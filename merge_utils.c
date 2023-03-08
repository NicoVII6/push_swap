/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:19:07 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 17:39:14 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.H"
#include <stdio.h> // juste pour tester !!

#define MAX_INPUT_SIZE 10000

// reflechir au type de la fonction ?? void parait bizarre puisqu'on a besoin de retourner
// un pointeur sur l'array triee
// Attention, il faut veiller a garder un pointeur sur l'array avant tri
// Utiliser un pointeur de pointeur ??
int		merge_recursive(int arr[], int low, int high)
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

int		merge_sort(int arr[], int low, int mid, int high)
{
	int	left_size;
	int	right_size;
	int	i;
	int	j;
	int	k;
	int	*temp_left;
	int	*temp_right;
	int	*sorted_arr;

	left_size = mid - low + 1;
	right_size = high - mid;
	temp_left = malloc(sizeof(int) * left_size);
	temp_right = malloc(sizeof(int) * right_size);
	sorted_arr = malloc((left_size + right_size) * sizeof(int));
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
