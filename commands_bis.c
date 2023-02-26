#include <stdio.h>
#include <stdlib.h>

// Définition d'un nœud de la liste chaînée
typedef struct Node {
    int data;
    struct node* next;
} Node;

// Fonction pour créer un nouveau nœud au debut de la liste
Node* newNode(int data) {
    Node* node = malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Fonction pour ajouter un nœud en haut de la pile a
void pushA(Node** topA, int data) {
    Node* node = malloc(sizeof(node));
    node->data = data;
    node->next = *topA;
    *topA = node;
}

// Fonction pour ajouter un nœud en haut de la pile b
// la liste chainée n'est pas directement passée en argument. A la place,
// la liste est passée ds la fonction comme un pointeur référence du pointeur topB
// The traditional method to allow a function to change its caller's memory is to
// pass a pointer to the caller's memory instead of a copy
// in this case, the value we want to
// change is struct node*, so we pass a struct node** instead. The two stars
// (**) are a little scary, but really it's just a straight application of the rule. It just happens
// that the value we want to change already has one star (*), so the parameter to change it
// has two (**). Or put another way: the type of the head pointer is "pointer to a struct
// node." In order to change that pointer, we need to pass a pointer to it, which will be a
// "pointer to a pointer to a struct node".
void pushB(Node** topB, int data) {
    struct Node* newNode;
    newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *topB; // on dereference pour accéder et changer la valeur d'intérêt
    *topB = newNode; // on assigne le nouveau noeud au haut de la pile
}

// Fonction pour supprimer le nœud en haut de la pile a
void popA_top(Node** topA) {
    if (*topA == NULL) {
        return;
    }
    struct node* temp = malloc(sizeof(Node));
    temp = *topA;
    *topA = topA->next;
    free(temp);
}

// Fonction pour supprimer le nœud en haut de la pile b
void popB_top(Node** topB) {
    if (*topB == NULL) {
        return;
    }
    struct Node* temp = malloc(sizeof(Node));
    temp = *topB;
    *topB = (*topB)->next;
    free(temp);
}

// Fonction pour supprimer le dernier élément de la pile A
void popA_tail(Node** topA) {
    if (*topA == NULL) {
        return;
    }
    if ((*topA)->next == NULL) {
        free(*topA);
        *topA = NULL;
        return;
    }
    struct Node* temp = malloc(sizeof(Node));
    temp = *topA;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Fonction pour supprimer le dernier élément de la pile B
void popB_tail(Node** topB) {
    if (*topB == NULL) {
        return;
    }
    if ((*topB)->next == NULL) {
        free(*topB);
        *topB = NULL;
        return;
    }
    struct Node* temp = malloc(sizeof(Node));
    temp = *topB;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Fonction pour intervertir les deux premiers éléments de la pile a
void sa(Node** topA) {
    if (*topA == NULL || (*topA)->next == NULL) {
        return;
    }
    int temp = (*topA)->data;
    (*topA)->data = (*topA)->next->data;
    (*topA)->next->data = temp;
}

// Fonction pour intervertir les deux premiers éléments de la pile b
void sb(Node** topB) {
    if (*topB == NULL || (*topB)->next == NULL) {
        return;
    }
    int temp = (*topB)->data;
    (*topB)->data = (*topB)->next->data;
    (*topB)->next->data = temp;
}

// Fonction pour intervertir les deux premiers éléments des piles a et b
void ss(Node** topA, Node** topB) {
    sa(topA);
    sb(topB);
}

// Fonction pour transférer le premier élément de la pile b à la pile a
void pa(Node** topA, Node** topB) {
    if (*topB == NULL) {
        return;
    }
    int data = (*topB)->data;
    pushA(topA, data);
    popB(topB);
}

// Fonction pour transférer le premier élément de la pile a à la pile b
void pb(Node** topA, Node** topB) {
    if (*topA == NULL) {
        return;
    }
    int data = (*topA)->data;
    pushB(topB, data);
    popA(topA);
}

// Fonction pour faire tourner les éléments de la pile a
void ra(Node** topA) {
    if (*topA == NULL || (*topA)->next == NULL) {
        return;
    }
    Node* temp = *topA;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *topA;
    *topA = (*topA)->next;
    temp->next->next = NULL;
}

// Fonction pour faire tourner les éléments de la pile b
void rb(Node** topB) {
    if (*topB == NULL || (*topB)->next == NULL) {
        return;
    }
    Node* temp = *topB;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = *topB;
    *topB = (*topB)->next;
    temp->next->next = NULL;
}

// Fonction pour faire tourner les éléments des piles a et b
void rr(Node** topA, Node** topB) {
    ra(topA);
    rb(topB);
}

// Fonction pour faire tourner les éléments de la pile a dans l'autre sens
void rra(Node** topA) {
    if (*topA == NULL || (*topA)->next == NULL) {
        return;
    }
    Node* temp = *topA;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = NULL;
    last->next = *topA;
    *topA = last;
}

// Fonction pour faire tourner les éléments de la pile b dans l'autre sens
void rrb(Node** topB) {
    if (*topB == NULL || (*topB)->next == NULL) {
        return;
    }
    Node* temp = *topB;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    Node* last = temp->next;
    temp->next = NULL;
    last->next = *topB;
    *topB = last;
}

// Fonction pour faire tourner les éléments des piles a et b dans l'autre sens
void rrr(Node** topA, Node** topB) {
    rra(topA);
    rrb(topB);
}