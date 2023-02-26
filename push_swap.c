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

void	push_swap(void)
{
	// choisir fonctions a utiliser selon le nombre total de randoms numbers
	
	// pour Radix sort
	// 1) trouver la valeur max de la liste (get_max_value)
	// 2) separer les nombres negatifs des nombres positifs dans des listes
	// 3) compter le nb de digits de chaque valeur (get_numbers_digits)
	// 4) utiliser counting sort by digits with an array of k empty lists
}

// counting sort with list :
// L = array of k empty lists (k = somme du nb de digits de la plus grande valeur)
// for j in range n (n = au nb total de numeros a trier)
//	L[key(A[j])].append(A[j])		meaning ??
// output=[]
// for i in range (k)
// output.extend(L[i])

// Liste chainée, ajout et double pointeurs

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

void	count_sort(Node **headRef)
{
	int	max = get_max_value(*headRef);
	int digits = count_digits(max);
	int	pass; // utile pour connaitre le chiffre sur lequel notre radix s'effectue
	int	i; // utile pour naviguer dans les cases indexées de bucket

	pass = 1; // premier passage: les unités, 2e passage: les dizaines.....
	while (pass <= digits)
	{
		// a chaque itération de la boucle while, on créé une liste output vide
		// et un tableau de pointeurs bucket de 10 éléments initialisé à NULL
		// ainsi qu'une variable current qui pointe sur le headRef
		Node *output = NULL;
		Node *bucket[10] = { NULL };
		Node *current = *headRef;
		// on calcule l'indice de la case du tableau bucket dans laquelle on doit placer le noeud courant
		while (current != NULL)
		{
			int	index = (current->data / pass) % 10; // permet de situé valeur (radix) sur notre tableau d'index
			Node *temp = current->next; // on créé une variable temporaire qui pointe vers le noeud suivant de current
			current->next = NULL; // on détache current de la liste chainée en assignant NULL à son pointeur next
			if (bucket[index] == NULL)
				bucket[index] = current;
			else
			{
				Node *last = bucket[index]; // on place current dans la case correspondante du tableau bucket
				// si la case du tableau bucket est deja occupée par un noeud, 
				// on parcourt la liste chainée à l'intérieur de cette case jusqu'à trouver son dernier noeud
				while (last->next != NULL)
					last = last->next; 
				// on fait pointer le next de ce dernier noeud vers current
				last->next = current;
			}
			current = temp; // on met à jour current en lui assignant temp (pointer originalement vers current->next)
		}
		i = 0;
		// on itère à travers le tableau bucket pour collecter les noeuds triés sur chaque indice
        while (i <= 9)
		{
            if (bucket[i] != NULL)
			{
                if (output == NULL) // si liste output est nulle
                    output = bucket[i]; // met a jour le pointeur de output vers le premier noeud de la case index de bucket
				//si bucket indice i contient des éléments,
                else
				{
                    Node* last = output; // on créé variable last qui pointe vers premier noeud output
					// on parcourt la liste jusqu'a obtenir son dernier noeud en utilisant last qui pointe vers le noeud courant
                    while (last->next != NULL)
                        last = last->next; // on fait pointer last sur le prochain noeud
					last->next = bucket[i]; // on fait pointer le dernier noeud trouvé vers le premier noeud
					// de la liste chainée bucket, 
					//cela permet de rajouter tous les noeuds de buckets a la fin de output
                }
            }
			i++; // on passe a l'indice suivant de bucket
        }
		*headRef = output; // on met a jour le pointeur de la liste chainée avec output
		pass++; // on incrémente pass pour passer au prochain digit des nombres
	}
}

void WrongPush(struct node* head, int data) {
struct node* newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = head;
head = newNode; // NO this line does not work!
}

void WrongPushTest() {
List head = BuildTwoThree();
WrongPush(head, 1); // try to push a 1 on front -- doesn't work
}

/* WrongPush() is very close to being correct. It takes the correct 3-Step Link In and puts it
an almost correct context. The problem is all in the very last line where the 3-Step Link
In dictates that we change the head pointer to refer to the new node. What does the line
head = newNode; do in WrongPush()? It sets a head pointer, but not the right one. It
sets the variable named head local to WrongPush(). It does not in any way change the
variable named head we really cared about which is back in the caller WrontPushTest().*/

/* We need Push() to be able to change some of the caller's memory — namely the head
variable. The traditional method to allow a function to change its caller's memory is to
pass a pointer to the caller's memory instead of a copy. So in C, to change an int in the
caller, pass a int* instead. To change a struct fraction, pass a struct
fraction* intead. To change an X, pass an X*. So in this case, the value we want to
change is struct node*, so we pass a struct node** instead. The two stars
(**) are a little scary, but really it's just a straight application of the rule. It just happens
that the value we want to change already has one star (*), so the parameter to change it
has two (**). Or put another way: the type of the head pointer is "pointer to a struct
node." In order to change that pointer, we need to pass a pointer to it, which will be a
"pointer to a pointer to a struct node".
Instead of defining WrongPush(struct node* head, int data); we define
Push(struct node** headRef, int data);. The first form passes a copy of
the head pointer. The second, correct form passes a pointer to the head pointer. The rule
is: to modify caller memory, pass a pointer to that memory. The parameter has the word
"ref" in it as a reminder that this is a "reference" (struct node**) pointer to the
head pointer instead of an ordinary (struct node*) copy of the head pointer.*/

/*
Takes a list and a data value.
Creates a new link with the given data and pushes
it onto the front of the list.
The list is not passed in by its head pointer.
Instead the list is passed in as a "reference" pointer
to the head pointer -- this allows us
to modify the caller's memory.
*/
void Push(struct node** headRef, int data) {
struct node* newNode = malloc(sizeof(struct node));
newNode->data = data;
newNode->next = *headRef; // The '*' to dereferences back to the real head
*headRef = newNode; // ditto
}
void PushTest() {
struct node* head = BuildTwoThree();// suppose this returns the list {2, 3}
Push(&head, 1); // note the &
Push(&head, 13);
// head is now the list {13, 1, 2, 3}
}

// Return the number of nodes in a list (while-loop version)
int Length(struct node* head) {
int count = 0;
struct node* current = head;
while (current != NULL) {
count++;
current = current->next
}
return(count);
}

/* 2) Changing a Pointer With A Reference Pointer
Many list functions need to change the caller's head pointer. To do this in the C language,
pass a pointer to the head pointer. Such a pointer to a pointer is sometimes called a
"reference pointer". The main steps for this technique are...
• Design the function to take a pointer to the head pointer. This is the
standard technique in C — pass a pointer to the "value of interest" that
needs to be changed. To change a struct node*, pass a struct
node**.
• Use '&' in the caller to compute and pass a pointer to the value of interest.
• Use '*' on the parameter in the callee function to access and change the
value of interest. */

void ChangeToNull(struct node** headRef) { // Takes a pointer tothe value of interest
*headRef = NULL; // use '*' to access the value of interest
}

void ChangeCaller() {
struct node* head1;
struct node* head2;
ChangeToNull(&head1); // use '&' to compute and pass a pointer to
ChangeToNull(&head2); // the value of interest
// head1 and head2 are NULL at this point
}

// ajouter au debut de la liste chainée

struct node* AddAtHead() {
struct node* head = NULL;
int i;
for (i=1; i<6; i++) {
Push(&head, i);
}
// head == {5, 4, 3, 2, 1};
return(head);
}

/* Build — Special Case + Tail Pointer
Consider the problem of building up the list {1, 2, 3, 4, 5} by appending the nodes to the
tail end. The difficulty is that the very first node must be added at the head pointer, but all
the other nodes are inserted after the last node using a tail pointer. The simplest way to
deal with both cases is to just have two separate cases in the code. Special case code first
adds the head node {1}. Then there is a separate loop that uses a tail pointer to add all the
other nodes. The tail pointer is kept pointing at the last node, and each new node is added
at tail->next. The only "problem" with this solution is that writing separate special
case code for the first node is a little unsatisfying. Nonetheless, this approach is a solid
one for production code — it is simple and runs fast. */
struct node* BuildWithSpecialCase() {
struct node* head = NULL;
struct node* tail;
int i;
// Deal with the head node here, and set the tail pointer
Push(&head, 1);
tail = head;
// Do all the other nodes using 'tail'
for (i=2; i<6; i++) {
Push(&(tail->next), i); // add node at tail->next
tail = tail->next; // advance tail to point to last node
}
return(head); // head == {1, 2, 3, 4, 5};
}