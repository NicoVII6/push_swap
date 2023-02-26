/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bis.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 18:03:53 by ndecotti          #+#    #+#             */
/*   Updated: 2023/02/22 18:03:53 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
	int	date;
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
// donne le nombre de digits de l'int max de la liste chainée
int	count_digits(int max)
{
	int	digits;

	digits = 0;
	if (max < 0)
	{
		max *= -1;
		digits++;
	}
	if (max == 0)
		digits++;
	while (max != 0)
	{
		max = max / 10;
		digits++;
	}
	return digits;
}

void	radix_sort(Node **headRef)
{
	int	max = get_max_value(*headRef);
	int	pass = count_digits(max);
	int	j;

	while (j <= pass && (max / j) > 0)
	{
		count_sort(*headRef);
		j++;
	}
}
/* VOIR COMMENT SUBDIVISER LA FONCTION COUNT SORT EN DEUX PARTIES 
 * IMPLEMENTER LES COMMANDES POSSIBLES DANS PROGRAMME DE TRI 
 * CREER LE CODE POUR 10-15 nombres max a trier 
 * FAIRE LE MAKEFILE */

// A structure to represent a node of the linked list
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// A function to add a node at the end of the linked list
void append(Node **head, int data) {
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;

    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// A function to sort a linked list using radix sort
void radix_sort(Node **head) {
    // Create a bucket array of linked lists
    const int num_buckets = 10;
    Node *buckets[num_buckets] = {NULL};

    // Determine the maximum value in the list
    int max_value = 0;
    Node *current = *head;
    while (current != NULL) {
        if (current->data > max_value) {
            max_value = current->data;
        }
        current = current->next;
    }

    // Perform radix sort for each digit
    for (int position = 1; max_value / position > 0; position *= 10) {
        // Distribute the nodes into buckets based on the current digit
        current = *head;
        while (current != NULL) {
            int digit = (current->data / position) % 10;
            append(&buckets[digit], current->data);
            current = current->next;
        }

        // Reconstruct the list by concatenating the buckets in order
        *head = NULL;
        Node *tail = NULL;
        for (int i = 0; i < num_buckets; i++) {
            if (buckets[i] != NULL) {
                if (*head == NULL) {
                    *head = buckets[i];
                } else {
                    tail->next = buckets[i];
                }
                tail = buckets[i];

                // Set the next pointer of the last node in the bucket to NULL
                // to avoid forming a cycle in the list
                while (tail->next != NULL) {
                    tail = tail->next;
                }
                tail->next = NULL;

                // Reset the bucket
                buckets[i] = NULL;
            }
        }
    }
}