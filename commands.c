/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:19:41 by ndecotti          #+#    #+#             */
/*   Updated: 2023/02/12 11:19:41 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structure de notre liste principale
typedef struct node {
	int	value;
	struct	node *next;
} node;

// on créée une structure avec comme élément un pointeur sur node du top de
// notre liste chainée node
typedef struct stack {
	node *top
} stack;

// on alloue memoire et on initialise valeur du premier node de la stack
// qui représente la valeur du 1er node de la liste chainée
stack	*init_stack(void){
	stack	*s = malloc(sizeof(stack));
	s ->top = NULL;
	return s;
}

int	is_empty(stack *s) {
	return s->top = NULL;
}

// on prend la pile B (ou A) et la valeur qui équivaut au top de la pile B (ou A) en parametres
// on malloc le premier node de la pile B (ou A), on lui affecte la valeur de value du top de la pile A (ou B)
// on se déplace vers le node suivant connecté au haut de la pile A (ou B) et on lui affecte le node de la stack B (ou A)
// à qui on donne la valeur de n
void	push(stack *s, int value) {
	node	*n = malloc(sizeof(node));
	n->value = value;
	n->next = s->top;
	s->top = n;
}

// si la stack s est non NULLE on fait pointer sur n l'élément au top de cette liste
// on assigne a value la valeur de n (et donc la valeur tu top de la stack)
// on change la valeur du top de la stack par la valeur du node suivant (l'avant dernier)
// on libère la mémoire et on retourne value
int	pop(stack *s) {
	if (is_empty(s) == NULL)
		return 0;
	node	*n = s->top;
	int value = n->value;
	s->top = n->next;
	free(n);
	return value;
}

// controle si les deux premieres valeurs de la stack A existent, et
// ensuite les permute
void	swap_a(stack *a) {
	if (a->top == NULL || a->top->next == NULL) {
		return;
	}
	int	temp = a->top->value;
	a->top->value = a->top->next->value;
	a->top->next->value = temp;
}

void	swap_b(stack *b) {
	if (b->top == NULL || b->top->next == NULL)
		return;
	int	temp = b->top->value;
	b->top->value = b->top->next->value;
	b->top->next->value = temp;
}

void	swap_a_b(stack *a, stack *b) {
	swap_a(a);
	swap_b(b);
}

void	push_a(stack *a, stack *b) {
	if (b->top == NULL)
		return ;
	push(a, pop(b));
}

void	push_b(stack *a, stack *b) {
	if (a->top == NULL)
		return ;
	push(b, pop(a));
}

// on checke si la pile A contient un top et un avant premier
// on créé un pointeur n sur node a qui on lui assigne la valeur du top de la pike A
// ensuite tant que l'élément après le dernier listé n'est pas NULL on assigne à n l'élément suivant
// autrement dit tant que l'on arrive pas au dernier élément de la liste, n prends la valeur de l'élément qui suit
// si on arrive au dernier élément, on sort de la boucle et on fait pointer last sur le node du dernier élément de cette liste
// on ramène ensuite la valeur du dernier élément au top de A et ainsi le rotate a est effectué
void	reverse_rotate_a(stack *a) {
	if (a->top == NULL || a->top->next == NULL)
		return;
	node	*n = a->top;
	while (n->next->next != NULL)
		n = n->next;
	node	*last = n->next;
	n->next = NULL;
	a->top = last;
}

void	reverse_rotate_b(stack *b) {
	if(b->top == NULL || b->top->next == NULL)
		return;
	node	*n = b->top;
	while (n->next->next != NULL)
		n = n->next;
	node	*last = n->next;
	n->next = NULL;
	b->top = last;
}

void	reverse_rotate_both(stack *a, stack *b) {
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}

// a revoir et confirmer
void	rotate_a(stack *a)
{
	if (a->top == NULL || a->top->next == NULL)
		return;
	node	*n = a->top;
	while (n->next->next != NULL)
		n = n->next;
	n->next->next = a->top;
	a->top = NULL;
}