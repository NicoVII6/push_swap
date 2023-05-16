/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/16 18:23:28 by ndecotti         ###   ########.fr       */
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
t_stack 	*ft_stkpop_push(t_stack **stack);
int			ft_stkpop(t_stack **stack);
void		ft_stkpush(t_stack **stack, int data);
void		stkpush_parsing(t_stack **stack, t_stack *new_node);
void		ft_stkclear(t_stack **stack);

//utils3
void		ft_putstr_fd(char *s, int fd);
int			is_sorted(t_stack **stack);
void		ft_error(t_stack **stack_a, t_stack **stack_b);

//utils4
int			get_index_from_value(t_stack **stack, int num);
int			get_data_from_index(t_stack **stack, int index);

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
int			check_duplicate(int *arr, int size);
long		ft_atol(const char *str);
int			ft_atoi(const char *str);

//normalize
t_stack		*ptr_to_maximum(t_stack *stack);
t_stack		*ptr_to_minimum(t_stack *stack);
t_stack		*normalize(t_stack *stack_a);

//radix_sort
//int			get_max_value(t_stack **stack_a);
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

//checking
void	print_list(t_stack **stack);
void	db_show_stack(t_stack **stack_a, t_stack **stack_b);

#endif