/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/12 15:09:02 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stdio.h>
# include <fcntl.h>
# include <stddef.h>

//#define TRUE 1
//#define FALSE 0

typedef struct s_stack
{
	int				data;
	struct	s_stack	*next;
}	t_stack;

//stack functions
t_stack		*ft_stknew(int data);
int			ft_stkisempty(t_stack *stack);
int			ft_stkpeek(t_stack *stack);
int			ft_stksize(t_stack *stack);
int			ft_stkpop(t_stack **stack);
void		ft_stkpush(t_stack **stack, int data);
void		stkpush_parsing(t_stack **stack, t_stack *new_node);
void		ft_stkclear(t_stack **stack);

//utils3
void		ft_putstr_fd(char *s, int fd);
t_stack		*decimal_to_binary(t_stack **stack_a);
int			dec_to_bin_convert(int decimal_val);
int			is_sorted(t_stack **stack);
void		ft_error(t_stack **stack_a, t_stack **stack_b);

//utils4
int			get_index_from_value(t_stack **stack, int num);
int			get_data_from_index(t_stack **stack, int index);

//homemade_algo

//int			get_min_value(t_stack *stack_a);
//int			get_min_value(t_stack **stack_a);
t_stack		*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc);

//algo_choice
void		algo_choice(t_stack **stack_a, t_stack **stack_b, int argc);
t_stack		*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc);

//sort_small_numbers
void		three_numb_sort(t_stack **stack_a);
void		four_numb_sort(t_stack **stack_a, t_stack **stack_b);
void		five_numb_sort(t_stack **stack_a, t_stack **stack_b);

//parsing
int			parse_args(t_stack **stack_a, int argc, char *argv[]);
int			check_str_figures(char *str);
//int			check_duplicate(t_stack *stack_a, int num);
int			check_duplicate(int *arr, int size);
long		ft_atol(const char *str);
int			ft_atoi(const char *str);

//normalize
t_stack		*ptr_to_maximum(t_stack *stack);
t_stack		*ptr_to_minimum(t_stack *stack);
t_stack		*normalize(t_stack *stack_a);

//radix_sort
int			get_max_value(t_stack **stack_a);
t_stack		*radix_sort(t_stack **stack_a, t_stack **stack_b);

//utils_split
size_t		ft_strlen(const char *str);
size_t		ft_strlcpy(char *dst, const char *src, size_t len);
char		**ft_split(const char *s, char c);

//commands_finals
void		swap_a(t_stack **stack);
void		rotate_a(t_stack **stack);
void		reverse_rotate_a(t_stack **stack);
void		push_a(t_stack **stacks_b, t_stack **stacks_a);
void		push_b(t_stack **stacks_a, t_stack **stacks_b);
//void		push_b_algo(int min, t_stack **stack_b);
//void		push_a_algo(int min, t_stack **stack_a);

//checking
void	print_list(t_stack **stack);
void	db_show_stack(t_stack **stack_a, t_stack **stack_b);
//void	display_lst(t_dlist **ptr_to_head, char *name);
//void	display_node(t_dlist *list);

#endif