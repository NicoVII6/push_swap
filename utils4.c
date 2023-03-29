/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils4.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 11:06:42 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/29 11:06:42 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

// double linked list
typedef struct s_dlist
{
	long			content; // pour éviter segfault si data > INT_MAX ou < INT_MIN
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

// structure qui contient les listes a et b et un compteur
typedef struct s_lists
{
	t_dlist	*a;
	t_dlist	*b;
	size_t	count;
}	t_lists;

// get to a particular index in the list
int		get_index(t_dlist *s, int num)
{
	int	i;
	t_dlist *temp;

	temp = s;
	i = 0;
	while (temp != NULL)
	{
		if (temp->content == num)
			return (i);
		temp = temp->next;
		i++;
	}
	return(-1);
}

// return the data contains in an particular index in the list
int		get_the_data(t_dlist *s, int index)
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
	return (temp->content);
}

// function which prints a list
void	ps_lstprint(t_dlist *lst)
{
	t_dlist	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%ld\n", tmp->content);
		tmp = tmp->next;
	}
}

// returns the maximum value of the list
long	get_max_value(t_dlist *a)
{
	long	max;
	t_dlist *temp;

	temp = s;
	max = a->content;
	while (temp)
	{
		if (temp->content > max)
		{
			max = temp->content;
		}
		temp = temp->next;
	}
	return (max);
}

// function which parse arguments into stack a
// returns a pointer to the stack
t_lists	*parse_args(t_lists *stacks, int ac, char *av[])
{
	int		i;
	long	tmp;

	i = 1;
	// means that there is only one argument ? 2 arguments ? why start with argv[0] ?
	// and not argv[1]
	if (ac == 2)
		i = 0;
	while (av[i])
	{
		if (!ps_str_is_posneg(av[i]))
			ps_error(stacks);
		tmp = ft_atol(av[i]);
		if (tmp > INT_MAX || tmp < INT_MIN)
			ps_error(stacks);
		if (ps_duplicate(stacks->a, tmp))
			ps_error(stacks);
		// si la stack a n'existe pas, on la créée (avec malloc) et on ajoute 1er agurment
		if (!stacks->a)
			stacks->a = ps_lstnew(tmp);
		// sinon on ajoute l'argument à la suite (par le haut) dans la liste
		else
			ps_lstadd_back(&stacks->a, ps_lstnew(ft_atoi(av[i])));
		i++;
	}
	return (stacks);
}

// créer nouvelle liste et la configurer pour pouvoir utiliser ensuite
// ps_list_add_back ou ps_list_add_front
t_dlist	*ps_lstnew(int content)
{
	t_dlist	*new;

	new = malloc(sizeof(t_dlist));
	if (!new)
		return (NULL);
	new->content = content;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

// chercher le premier élément de la liste (au top) 
// retourne un pointeur sur ce premier élément
// NULL si la liste est vide
t_dlist	*ps_lstfirst(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->prev)
		tmp = tmp->prev;
	return (tmp);
}


void	ps_lstadd_back(t_dlist **lst, t_dlist *new)
{
	t_dlist	*last;

	last = ps_lstlast(*lst);
	if (!last)
		*lst = new;
	last->next = new;
	new->prev = last;
}

void	ps_lstadd_front(t_dlist **lst, t_dlist *new)
{
	t_dlist	*curr;

	curr = *lst;
	curr->prev = new;
	new->next = *lst;
	*lst = new;
}

// retourne le nombre d'éléments de la liste
int	ps_lstsize(t_dlist *lst)
{
	t_dlist	*tmp;
	int		i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

// retourne un pointeur sur le dernier élément de la liste
t_dlist	*ps_lstlast(t_dlist *lst)
{
	t_dlist	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// clean un node dans une liste après un mouvement
void	ps_lstclear(t_dlist *lst)
{
	t_dlist	*tmp;

	while (lst)
	{
		tmp = lst->next;
		free(lst);
		lst = tmp;
	}
}