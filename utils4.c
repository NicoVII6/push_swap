/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:06:42 by ndecotti          #+#    #+#             */
/*   Updated: 2023/04/08 15:31:53 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// get to a particular index in the list according to a particular value
int		get_index_from_value(t_dlist *s, int num)
{
	int	i;
	t_dlist *temp;

	temp = s;
	i = 0;
	while (temp != NULL)
	{
		if (temp->data == num)
			return (i);
		temp = temp->next;
		i++;
	}
	return(-1);
}

// return the data contains in an particular index in the list
int		get_data_from_index(t_dlist *s, int index)
{
	int	i;
	t_dlist *temp;

	temp = s;
	i = 0;
	while (i < index)
	{
		temp = temp->next;
		i++;
	}
	return (temp->data);
}

// returns the maximum value of the list
/*long	get_max_value(t_dlist *a)
{
	long	max;
	t_dlist *temp;

	temp = a;
	max = a->data;
	while (temp)
	{
		if (temp->data > max)
		{
			max = temp->data;
		}
		temp = temp->next;
	}
	return (max);
}*/


// créé nouvelle liste, y ajoute une valeur
t_dlist	*new_list(int data)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->data = data;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_to_head(t_dlist **list, t_dlist *new)
{
	t_dlist	*last;

	last = go_to_head(*list);
	if (!last)
		*list = new;
	last->next = new;
	new->prev = last;
}

// retourne un pointeur sur le dernier element ajouté (head) de la liste
// retourne NULL si liste est vide / un pointeur sur l'element sinon
t_dlist	*go_to_head(t_dlist *list)
{
	t_dlist	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	add_to_tail(t_dlist **list, t_dlist *new)
{
	t_dlist	*head;

	head = go_to_tail(*list); // on dereference avec * car double pointeur
	head->prev = new;
	new->next = *list;
	//new->next = head;
	*list = new;
}

// cherche le premier element ajouté ds la liste (tail)
// retourne un pointeur sur ce premier élément
// NULL si la liste est vide
t_dlist	*go_to_tail(t_dlist *list)
{
	t_dlist	*tmp;

	if (!list)
		return (NULL);
	tmp = list;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}

// clean un node dans une liste après un mouvement
void	clear_list(t_dlist *list)
{
	t_dlist	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
}