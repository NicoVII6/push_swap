/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 16:09:33 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stddef.h>
//# include <stdio.h>

typedef struct s_stack
{
	long			data;
	struct s_stack	*next;
}	t_stack;

void	cleanup_stacks(t_stack **stack_a, t_stack **stack_b);
void	cleanup_argv(char ***argv);
void	shift_argv(int *argc, char ***argv);
void	process(int *argc, char ***argv, t_stack **stack_a, t_stack **stack_b);

//stack functions
t_stack	*ft_stknew(int data);
t_stack	*ft_stkpop_push(t_stack **stack);
int		ft_stkpop(t_stack **stack);
void	ft_stkpush(t_stack **stack, int data);
void	ft_stkclear(t_stack **stack);

//stack functions bis
int		ft_stkisempty(t_stack *stack);
int		ft_stkpeek(t_stack *stack);
int		ft_stksize(t_stack *stack);

//utils3
int		is_sorted(t_stack **stack);
void	ft_error(t_stack **stack_a, t_stack **stack_b);

//algo_choice
void	algo_choice(t_stack **stack_a, t_stack **stack_b, int argc);
t_stack	*small_numb_sort(t_stack **stack_a, t_stack **stack_b, int argc);

//sort_small_numbers
void	three_numb_sort(t_stack **stack_a);
void	four_numb_sort(t_stack **stack_a, t_stack **stack_b);
void	five_numb_sort(t_stack **stack_a, t_stack **stack_b);

//small sort execution
void	execute_move(t_stack **stack);
void	execute_move2(t_stack **stack);
void	execute_move3(t_stack **stack);
void	execute_move4(t_stack **stack_a);

//parsing
int		parse_args(t_stack **stack_a, int argc, char *argv[]);
void	reverse_push_stack(t_stack **stack, int *arr, int argc);
int		validate_array(int *arr, int argc);
int		fill_array(int *arr, char **argv);

//parsing_bis
int		check_str_figures(char *str);
int		check_duplicate(int *arr, int size);
long	ft_atol(const char *str);
int		ft_atoi(const char *str);

//normalize
t_stack	*ptr_to_maximum(t_stack *stack);
t_stack	*ptr_to_minimum(t_stack *stack);
t_stack	*normalize(t_stack *stack_a);

//radix_sort
t_stack	*radix_sort(t_stack **stack_a, t_stack **stack_b);

//utils_split
size_t	ft_strlen(const char *str);
size_t	ft_strlcpy(char *dst, const char *src, size_t len);

//split
char	**ft_split(const char *s, char c);

//commands_finals
void	swap_a(t_stack **stack);
void	rotate_a(t_stack **stack);
void	reverse_rotate_a(t_stack **stack);
void	push_a(t_stack **stacks_b, t_stack **stacks_a);
void	push_b(t_stack **stacks_a, t_stack **stacks_b);

//checking
//void	db_show_stack(t_stack **stack_a, t_stack **stack_b);

#endif