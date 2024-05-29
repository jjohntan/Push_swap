
#include "../inc/push_swap.h"

int	get_rank(t_stack_node **a, int n)
{
	t_stack_node	*current;
	t_stack_node	*next_node;
	int	rank;

	rank = 0;
	current = *a;
	while (current->next)
	{
		next_node = current->next;
		while (next_node->next)
		{
			if (next_node->nbr < current->nbr)
				rank++;
		}
	}
	return (rank);
}

void	stable_sort(t_stack_node **a)
{
	t_stack_node	*current;
	t_stack_node	*next_node;
	int	temp;
	
	current = *a;
	while (current)
	{
		while (next_node)
		{
			if (next_node->nbr < current->nbr)
			{
				temp = current->nbr;
				current->nbr = next_node->nbr;
				next_node->nbr = temp;
			}
			next_node = next_node->next;
		}
		current = current->next;
	}
}
