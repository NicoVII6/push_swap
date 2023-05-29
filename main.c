/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/02 14:54:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/05/24 16:20:34 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	process(int *argc, char ***argv, t_stack **stack_a, t_stack **stack_b)
{
	char	**split_args;

	split_args = ft_split((const char *)(*argv)[1], ' ');
	*argc = 0;
	if (split_args == NULL)
		ft_error(stack_a, stack_b);
	while (split_args[*argc])
		(*argc)++;
	*argv = split_args;
}

void	shift_argv(int *argc, char ***argv)
{
	(*argv)++;
	(*argc)--;
}

void	cleanup_argv(char ***argv)
{
	int	i;

	i = 0;
	while ((*argv)[i])
	{
		free((*argv)[i]);
		i++;
	}
	free(*argv);
}

void	cleanup_stacks(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_stksize(*stack_a) > 0)
		ft_stkclear(stack_a);
	if (ft_stksize(*stack_b) > 0)
		ft_stkclear(stack_b);
	free(*stack_a);
	free(*stack_b);
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;

	flag = 0;
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		flag = 1;
		process(&argc, &argv, &stack_a, &stack_b);
	}
	else
		shift_argv(&argc, &argv);
	if (parse_args(&stack_a, argc, argv) == 1)
		ft_error(&stack_a, &stack_b);
	if (flag == 1)
		cleanup_argv(&argv);
	normalize(stack_a);
	algo_choice(&stack_a, &stack_b, argc);
	cleanup_stacks(&stack_a, &stack_b);
	return (0);
}
/*
int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		flag;
	
	flag = 0;
	if (argc < 2)
		return (1);
	stack_a = NULL;
	stack_b = NULL;
	if (argc == 2)
	{
		flag = 1;
		argv = ft_split((const	char *) argv[1], ' ');
		argc = 0;
		if (argv == NULL)
			ft_error(&stack_a, &stack_b);
		while (argv[argc])
			argc++;
	}
	else
	{
		argv++;
		argc--;
	}
	if (parse_args(&stack_a, argc, argv) == 1)
		ft_error(&stack_a, &stack_b);
	if (flag == 1)
	{
		int		i;

		i = 0;
		while (argv[i])
		{
			free(argv[i]);
			i++;
		}
	free(argv);
	}
	normalize(stack_a);
	algo_choice(&stack_a, &stack_b, argc);
	if (ft_stksize(stack_a) > 0)
		ft_stkclear(&stack_a);
	if (ft_stksize(stack_b) > 0)
		ft_stkclear(&stack_b);
	free(stack_a);
	free(stack_b);
	return (0);
}
*/