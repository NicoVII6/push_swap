/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   merge_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/05 17:19:07 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/05 17:33:23 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.H"
#include <stdio.h> // juste pour tester !!

#define MAX_INPUT_SIZE 10000

// reflechir au type de la fonction ?? void parait bizarre puisqu'on a besoin de retourner
// un pointeur sur l'array triee
// Attention, il faut veiller a garder un pointeur sur l'array avant tri
// Utiliser un pointeur de pointeur ??
void	merge_recursive(int arr[], int temp[], int low, int high)
{
	int	mid;

	if (low >= high)
		return;
	// signifie que la subdivision est finie
	mid = (low + high) / 2;
	merge_recursive(arr, temp, low, mid);
	merge_recursive(arr, temp, mid + 1, high); // right portion starts with index mid + 1
	merge_sort(arr, temp, low, mid, high);
}

// revoir pour les parametresd de la fonction, surtt int temp[]
// utiliser un pointeur sur int pour la fonction ??
int		merge_sort(int arr[], int temp[], int low, int mid, int high)
{
	int	left_size;
	int	right_size;
	int	i;
	int	j;
	int	k;
	int	temp_left[left_size];
	int	temp_right[right_size];

	left_size = mid - low + 1;
	right_size = high - mid;
	i = 0;
	while (i < left_size)
	{
		temp_left[i] = arr[low + i];
		i++;
	}
	while (i < right_size)
	{
		temp_left[i] = arr[mid + 1 + i];
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
	while (k <= high)
	{
		// la 1ere condition nous dit que si i n'est pas strictement inferieur a left_size
		// c'est qu'on a atteint la fin du tableau gauche. On ne va donc plus rien copier de temp_left
		// on passe donc directement au else pour copier le reste de temp_right
		// si la 2e condition n'est pas respectee, on copie directement les temp_left restant
		// la 3e condition est la uniquement pour trancher si les 2 premieres condtions sont respectees
		if ((i < left_size) && (j >= right_size) || temp_left[i] < temp_right[j])
		{
			arr[k] = temp_left[i];
			k++;
			i++;
		}
		else
		{
			arr[k] = temp_right[j];
			k++;
			i++;
		}
	}
	return (arr);
}
