/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 17:41:19 by ndecotti          #+#    #+#             */
/*   Updated: 2023/02/17 17:53:37 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define BUCKETS 10

typedef struct Node {
	int	value;
	struct	Node *next;
} Node;

typedef struct stack {
	Node *top
} stack;

stack	*init_stack(void){
	stack	*s = malloc(sizeof(stack));
	s->top = NULL;
	return s;
}

// compter le nombre de digits d'un nombre

int	get_number_digits(int value)
{
	int	digits = 0;
	while (value > 0)
	{
		value /= 10;
		digits++;
	}
	return digits;
}

// insert un nouveau top Node a la liste chainee
// la fonction pointe sur la structure et le pointeur top sur le premier Node de celle ci

Node	*insert(stack *s, int value)
{
	Node *newNode = malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = s->top;
	return newNode;
}

// insert a la fin de la liste chainee

Node	*insert_end(stack *s, int value)
{
	Node	*newNode = malloc(sizeof(Node));
	if (newNode == NULL)
		return;
	newNode->value = value;
	newNode->next = NULL; // signifie que le node d'apres est bien nul
	if (s->top == NULL)
		s->top == newNode;
	else
	{
		Node	*curr = s->top;
		while (curr->next != NULL)
			curr = curr->next;
		curr->next = newNode;
	}
	return s->top;
}

// determiner le grand nombre de la liste (tout signe confondu)

int	get_max_value(stack *s)
{
	Node	*n = s->top;
	int	max = n->value;
	while (n->next->next != NULL)
	{
		if (n->value > max)
			max = n->value;
		n = n->next;
	}
	return max;
}

/* cette fonction est utilisee pour ajouter un nouvel element a un bucket d'index particulier correspondant
 au tri radix. Au depart nous avons une array de buckets indexes de 0 a 9
 Nous avons en input la valeur que nous souhaitons ajouter 
 (possible de le faire en prenant l'ensemble des valeurs) pour laquelle l index du bucket auquelle elle
 appartient est determinee par la formule value % 10
 Nous creons ensuite une structure de Node pour stocker la value 
 ce nouveau Node est ajoute au top de la liste de l'index correspondand
 on repete ensuite le processus jusqu a ce que toutes les valeurs soient placee
 */
void	append_to_bucket(struct Node *bucket[BUCKETS], int value)
{
	int	bucketIndex = value % 10;
	struct Node *newNode = malloc(sizeof(struct Node));
	newNode->value = value;
	newNode->next = bucket[bucketIndex];
	bucket[bucketIndex] = newNode;
}


// fonction a etudier qui permet de passer d une dizaine a une autre ds le radix process

void append_to_bucket(Node** bucket, int value, int digitPlace)
{
	int	bucketIndex;
	int	i;

	i = 0;
	// Node* node = malloc(sizeof(Node));
	while (i < digitPlace && value / 10 != NULL)
	{
		bucketIndex = value % 10;
		Node* node = malloc(sizeof(Node));
		node->value = value;
		node->next = bucket[bucketIndex];
		bucket[bucketIndex] = node;
		i++;
		value += value / 10;
	}
}