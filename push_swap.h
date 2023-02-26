#ifndef PUSH_SWAP_STRUCT_H
# define PUSH_SWAP_STRUCT_H

typedef struct s_dlist
{
	// long			content;
	int				data;
	struct s_dlist	*next;
	struct s_dlist	*prev;
}	t_dlist;

typedef struct s_lists
{
	t_dlist	*a;
	t_dlist	*b;
	size_t	count;
}	t_lists;

#endif

/* La première structure est appelée t_dlist. C'est une structure de liste doublement chaînée qui est utilisée pour stocker des éléments de données.
Cette structure a trois membres :
content est le contenu de la liste, ici stocké sous la forme d'un entier long.
next est un pointeur vers le prochain élément de la liste.
prev est un pointeur vers l'élément précédent de la liste.

cette structure permet de parcourir la liste dans les deux sens (en avant et en arrière)

La seconde structure est appelée t_lists. Elle utilise la structure t_dlist pour définir deux listes distinctes, notées a et b. 
a est un pointeur vers la première liste, qui contient les éléments à trier.
b est un pointeur vers la seconde liste, qui est initialement vide 
(sera utilisée comme zone de travail pour trier les éléments de la liste a.)
count est un entier qui représente le nombre total d'éléments dans les deux listes.

En utilisant les deux listes distinctes, ce programme implémente une variante de l'algorithme de tri "merge sort" (tri de fusion)
qui utilise des opérations de "push" et "swap" pour trier les éléments dans les deux listes.

Enfin, les lignes #ifndef PUSH_SWAP_STRUCT_H et # define PUSH_SWAP_STRUCT_H sont des instructions
qui permettent de s'assurer que ces structures ne sont définies qu'une seule fois
même si elles sont utilisées dans plusieurs fichiers source différents.
*/