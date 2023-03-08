/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bis.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:14:28 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:04 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PUSH_SWAP.H"


int	main(int argc, char *argv[])
{
	// check if there are enough arguments
	if (argc < 2)
	{
		ft_print(stderr, "Error\n");
		return 1;
	}
	// allocate memory for the array
	int	n = argc - 1;
	int	*arr = ft_calloc(n, sizeof(int));
	if (argc >= 3)
	// check for duplicates and parse the input integers
	int	*check_dupli = ft_calloc(UINT_MAX, sizeof(int));
	int	i = 0;
	while (i < n)
	{
		int	int_value = ft_atoi(argv[i + 1]);
		if (int_val < INT_MIN || int_val > INT_MAX)
		{
			fprintf(stderr, "Error\n", argv[i + 1]);
			return 1;
		}
		if(*check_dupli[int_val - INT_MIN] != NULL)
		{
			fprintf(stderr, "Error\n", int_val);
		}
	}
}