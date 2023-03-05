/* first while loop iterates from the first element of the array to the 
 * second-to-last-element (size - 1). This loop controls the number of iterations of 
 * the sort array algorithm */

/* the second while loop iterates from the next element after i (j = i + 1) to the
 * last element of the array (j < size). this inner loop compares adjacents elements
 * of the array and swap them if they are in the wrong order */

/* after the inner loop has completed, the outer loop continues with the next iteration
 * and the process continues until no more swaps are necessary */


// utilisation merge sort instead this counting one
void	sort_array(int arr[], int size)
{
	int	i;
	int	j;
	int	temp;
	
	i = 0;
	while (i < size - 1)
	{
		j = i + 1;
		while (j < size)
		{
			if (arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
			j++;
		}
		i++;
	}
}