/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 13:08:16 by ndecotti          #+#    #+#             */
/*   Updated: 2023/02/16 18:05:46 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud de la liste chaînée
typedef struct Node {
    int data;
    struct Node* next;
} Node;

int	list_length(struct Node *head)
{
	struct Node *current;
	int	count;

	current = head;
	count = 0;
	while (current != NULL)
	{
		count++;
		current = current->next;
	}
	return count;
}

int	get_max_value(Node *head)
{
	Node* max = head;
	if (head == NULL)
		return;
	max = head->data;
	Node* current = head->next;
	while (current->next != NULL)
	{
		current = current->next;
		if (current->data >= max)
			max = current;
	}
	return max;
}