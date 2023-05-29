/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/23 16:25:20 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/23 16:46:58 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	count_words(const char *s, char c)
{
	int	words;
	int	i;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			words++;
			while (s[i] != c && s[i])
				i++;
		}
		else
			i++;
	}
	return (words);
}
/* function takes a pointer to the array of strings as input
 * the loop runs as long as there are strings left in the array
 * free is called in the loop to free the current string in the array
 * the pointer to the current string in the array is incremented to
 * point to the next string until no string left in the array
 * Once all the strings in the array have been freed, free is called one more
 * time to free the allocated memory of the array itself.
 * Returns a NULL pointer to indicate that the memory has been freed */

static char	**free_all(char **arr)
{
	int		i;

	i = 0;
	while (arr[i])
	{
		free(arr[i]);
		i++;
	}
	free(arr);
	return (NULL);
}

/* The get_row function is called in a loop to extract each word
from the string. The function takes three arguments: a pointer to
the current position in the string (str), a pointer to the length
of the current word (str_len), and the delimiter character c.
The function moves the str pointer to the start of the next word in the string,
and updates the str_len variable with the length of the word. */

static void	get_row(char **str, int *str_len, char c)
{
	int	i;

	*str += *str_len;
	*str_len = 0;
	i = 0;
	while (**str && **str == c)
		(*str)++;
	while ((*str)[i])
	{
		if ((*str)[i] == c)
			return ;
		(*str_len)++;
		i++;
	}
}

/* split takes a string s and a delimiter char c as input
 * function returns a pointer to a dynamically allocated array of strings
 * count_words takes the string and the delimiter and returns the number
 * of words in the string 
 * then split allocates memory for an array of words_nb of strings
 * plus 1 for the NULL pointer that terminates the array
 * the str pointer is set to point the start of the string s
 * get_row function is called in a loop to extract each word from the string
 * for each word, memory is allocated to fill the array of strings previously
 * malloc with the size of the total number of words the string contains 
 * ft_strlcpy is called to copy the word from the original string to the array 
 * ft_splut returns a pointer to the array of strings */

char	**ft_split(const char *s, char c)
{
	char	**arr;
	char	*str;
	int		words_nb;
	int		i;
	int		str_len;

	words_nb = count_words(s, c);
	arr = malloc(sizeof(char *) * (words_nb + 1));
	if (!arr)
		return (NULL);
	str = (char *)s;
	i = 0;
	str_len = 0;
	while (i < words_nb)
	{
		get_row(&str, &str_len, c);
		arr[i] = malloc(sizeof(char) * (str_len + 1));
		if (arr[i] == NULL)
			return (free_all(arr));
		ft_strlcpy(arr[i], str, str_len + 1);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}
