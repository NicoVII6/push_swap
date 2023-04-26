/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ndecotti <ndecotti@student.42lausanne.c    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/29 16:14:42 by ndecotti          #+#    #+#             */
/*   Updated: 2023/03/29 16:14:42 by ndecotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv)
{
	/*MAIN OGANISATION :
on malloc les stacks t_lists : stacks = malloc(2 * sizeof(t_dlist));
on renvoie un message d'erreur si argc == 1
on initialise les stacks a et b à NULL; ainsi que le compteur des stacks (count) à 0
si argc == 2, split
utilisation fonction parse pour répartir arguments sur la stack (après avoir réussi tous les checks)
stack = parse_arguments(stacks, argc, argv);

ensuite on normalise les valeurs, (0 à N) avec un bubble sort qui compare chaque valeur
avec suivante à partir d'un endroit random dans la liste
sortira une liste triée sur laquelle on va s'appuyer actualiser les indices de la liste initiale
en gros on va créer une fonction qui va prendre le premier élément de la liste, accéder
à la valeur de cet élément, call une fonction qui va circuler ds la liste triée, et qui remplacera
la valeur initiale pointée par l'indice. 
Ainsi si la première valeur liste originale est 46, et que cette valeur se trouve être dans à la 10e
position après bubble sort, alors on remplacera dans la liste originale 46 par 10
et on répète l'opération jusqu'a ce que toutes les valeurs aient été remplacées
par leur indice correspondant.

ensuite on envoie cette liste pour la conversion en binaire
et derrière on execute le radix, sur deux piles comme demandé
on utilise les commandes autorisées pour dispatcher les valeurs en fonction 
de leur binaire

Ne pas oublier d'utiliser la fonction pour clear un node après mouvement */
}