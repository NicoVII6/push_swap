/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   commands.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 11:19:41 by ndecotti          #+#    #+#             */
/*   Updated: 2023/02/17 17:53:38 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// structure de notre liste chainee, avec pour chaque element, deux blocs :
// un integer et un pointeur vers le noeud suivant
typedef struct Node {
	int	value;
	struct	Node *next;
} t_Node;

// structure intermediaire qui nous permets de faire les manipulations avec les commandes
typedef struct stack {
	Node *top
} t_stack;

// on alloue memoire et on initialise valeur du premier Node de la stack a NULL
stack	*init_stack(void){
	stack	*s = malloc(sizeof(stack));
	s ->top = NULL;
	return s;
}

int	is_empty(stack *s) {
	return s->top == NULL;
}

// la fonction prends en parametre un pointeur vers la structure stack et une valeur
// on ajoute un nouveau noeud a la pile en faisant un malloc
// on assigne a ce pointeur, le bloc value
// on met a jour le pointeur next pour qu'il pointe en haut de la liste,
// ensuite on met a jour le pointeur top pour qu'il pointe vers le nouveau noeud créé
void	push(stack *s, int value) {
	Node	*n = malloc(sizeof(Node));
	n->value = value;
	n->next = s->top;
	s->top = n;
}

// la fonction pop recupere le pointeur top de la pile stack et sauvegarde la valeur
// de l'element pointe ds la variable value et met a jour le pointeur top de la pile stack 
// pour qu'il pointe vers l'element suivant
// la fonction pop retire l'element situee au sommet de la pile stack en liberant
// la memoire occupee par l'element retiré
int	pop(stack *s) {
	if (is_empty(s) == NULL)
		return 0;
	Node	*n = s->top;
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

// la fonction consiste a retirer l'element se trouvant au sommet de la pile b et a le
// placer sur la pile a
// la fonction verifie d'abord que la pile b n'est pas vide
// si pile b contient au moins un element, la fonction execute pop de b pour retirer l'element
// du sommet de la pile, l'ayant stocke au prealable dans la variable value
// ensuite elle appelle fonction push en prenant en argument la pile a et la value stockée de b
// pour l'ajouter au sommet de la pile a
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
// on cree un pointeur n qui pointe sur le premier element de la stack
// ensuite tant que l'on arrive pas a l'avant dernier noeud, la boucle while s'execute
// une fois sorti de la boucle, on stocke un pointeur vers le dernier noeud de la pile dans variable last
// on free ce noeud et on met a jour le pointeur top pour qu'il pointe vers ce dernier noeud, qui devient
// ainsi le nouveau premier noeud de la pile
void	reverse_rotate_a(stack *a) {
	if (a->top == NULL || a->top->next == NULL)
		return;
	Node	*temp = a->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	Node	*last = temp->next;
	temp->next = NULL;
	a->top = last;
}

void	reverse_rotate_b(stack *b) {
	if(b->top == NULL || b->top->next == NULL)
		return;
	Node	*temp = b->top;
	while (temp->next->next != NULL)
		temp = temp->next;
	Node	*last = temp->next;
	temp->next = NULL;
	b->top = last;
}

void	reverse_rotate_both(stack *a, stack *b) {
	reverse_rotate_a(a);
	reverse_rotate_b(b);
}

// on checke si la pile A contient un top et un deuxieme element
// on cree ensuite un pointeur temp qui pointe sur le premier element de la stack
// ensuite une boucle while s'execute dans la stack jusqu'a ce qu'on atteigne le dernier noeud
// une fois atteint, on fait pointer ce dernier noeud sur le premier de la stack
// on fait met a jour le pointeur top pour qu'il pointe sur le deuxieme element
// on assigne la valeur NULL au pointeur qui etait le premier noeud
void	rotate_a(stack *a)
{
	if (a->top == NULL || a->top->next == NULL)
		return;
	Node	*temp = a->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = a->top;
	a->top = a->top->next;
	a->top = NULL;
}

void	rotate_b(stack *b)
{
	if (b->top == NULL || b->top->next == NULL)
		return;
	Node	*temp = b->top;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = b->top;
	b->top = b->top->next;
	b->top = NULL;
}

void	rotate_both(stack *a, stack *b)
{
	rotate_a(a);
	rotate_b(b);
}