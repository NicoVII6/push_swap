/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/28 15:29:04 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/08 18:35:05 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>

#define INT_SIZE (sizeof(int) * CHAR_BIT)
#define INT_MAX ((1 << (INT_SIZE - 1)) - 1)
#define INT_MIN (-INT_MAX - 1)

/* In this code, INT_SIZE is the number of bits in an int data type. 
CHAR_BIT is a constant that represents the number of bits in a char data type (usually 8),
so sizeof(int) * CHAR_BIT calculates the number of bits in an int.

INT_MAX is defined as (1 << (INT_SIZE - 1)) - 1.
This expression shifts the binary value 1 to the left by INT_SIZE - 1 bits,
which sets the leftmost bit to 1 and all other bits to 0. Then, the expression
subtracts 1 to set all the bits except the leftmost bit to 1,
resulting in the maximum possible value for a signed integer.

INT_MIN is defined as -INT_MAX - 1. This expression negates INT_MAX and subtracts 1,
resulting in the minimum possible value for a signed integer. */

#define TRUE 1
#define FALSE 0