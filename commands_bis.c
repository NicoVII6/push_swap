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
    Node* node = newNode(data);
    node->next = *topA;
    *topA = node;
}

// Fonction pour ajouter un nœud en haut de la pile b
void pushB(Node** topB, int data) {
    Node* node = newNode(data);
    node->next = *topB;
    *topB = node;
}

// Fonction pour supprimer le nœud en haut de la pile a
void popA(Node** topA) {
    if (*topA == NULL) {
        return;
    }
    Node* temp = *topA;
    *topA = (*topA)->next;
    free(temp);
}

// Fonction pour supprimer le nœud en haut de la pile b
void popB(Node** topB) {
    if (*topB == NULL) {
        return;
    }
    Node* temp = *topB;
    *topB = (*topB)->next;
    free(temp);
}

// Fonction pour supprimer le dernier élément de la pile A
void popA(Node** topA) {
    if (*topA == NULL) {
        return;
    }
    if ((*topA)->next == NULL) {
        free(*topA);
        *topA = NULL;
        return;
    }
    Node* temp = *topA;
    while (temp->next->next != NULL) {
        temp = temp->next;
    }
    free(temp->next);
    temp->next = NULL;
}

// Fonction pour supprimer le dernier élément de la pile B
void popB(Node** topB) {
    if (*topB == NULL) {
        return;
    }
    if ((*topB)->next == NULL) {
        free(*topB);
        *topB = NULL;
        return;
    }
    Node* temp = *topB;
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