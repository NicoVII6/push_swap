/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 19:00:20 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include <fcntl.h>

#define TRUE 1
#define FALSE 0

// double linked list structure ac pointeurs sur previous and next elements
typedef struct s_dlist {
	long			data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

// structure qui contient les pointeurs a et b, qui pointent respectivement
// au top node de chaque liste
// est ce que count est necessaire dans le programme ??
typedef struct s_lists {
	t_dlist	*a;
	t_dlist	*b;
	size_t	count;
}	t_lists;

//utils3
void		ft_putstr_fd(char *s, int fd);
int			check_str_figures(char *str);
int			check_duplicate(t_dlist *a, int data);
t_dlist		*decimal_to_binary(t_dlist *a);
int			dec_to_bin_convert(int decimal_val);

//homemade_algo
t_dlist		*three_numb_sort(t_dlist *a);
t_dlist		*four_numb_sort(t_dlist *a, t_dlist *b);
t_dlist		*five_numb_sort(t_dlist *a, t_dlist *b);
t_dlist		*small_numb_sort(t_dlist *a, t_dlist *b);

//utils2
long		ft_atoi(const char *str);
int			list_size(t_dlist *a);
int			get_min_value(t_dlist *a);
int			get_max_value(t_dlist *a);
t_dlist		*ptr_to_maximum(t_dlist *a);
t_dlist		*ptr_to_minimum(t_dlist *a);


//utils4
int			get_index_from_value(t_dlist *s, int num);
int			get_data_from_index(t_dlist *s, int index);
t_dlist		*new_list(int data);
void		clear_list(t_dlist *list);
void		add_to_head(t_dlist **list, t_dlist *new);
void		add_to_tail(t_dlist **list, t_dlist *new);
t_dlist		*go_to_head(t_dlist *list);
t_dlist		*go_to_tail(t_dlist *list);

t_lists		*parse_args(t_lists *stacks, int argc, char *argv[]);
t_lists		*normalize(t_lists *stacks);
t_dlist		*radix_sort(t_dlist *a, t_dlist *b);

//utils_split
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
//static int	count_words(const char *s, char c);
//static char	**free_all(char **arr);
//static void	get_row(char **str, int *str_len, char c);
char		**ft_split(const char *s, char c);

//commands_finals
t_dlist		*swap_a(t_dlist *a);
t_dlist		*swap_b(t_dlist *b);
t_dlist		*rotate_a(t_dlist *a);
t_dlist		*rotate_b(t_dlist *b);
t_dlist		*reverse_rotate_a(t_dlist *a);
t_dlist		*reverse_rotate_b(t_dlist *b);
t_dlist		*push_a(t_dlist *b, t_dlist **a);
t_dlist		*push_b(t_dlist *a, t_dlist **b);