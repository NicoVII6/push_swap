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