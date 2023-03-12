/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/12 19:11:07 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef struct s_stack {
	int	top;
	int	*items;
	int	size
} t_stack;