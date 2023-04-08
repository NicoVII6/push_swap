#include "push_swap.h"

// function which prints a list of values
void	print_list(t_dlist *lst)
{
	t_dlist	*tmp;

	tmp = lst;
	while (tmp)
	{
		printf("%ld\n", tmp->data);
		tmp = tmp->next;
	}
}