/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:33:53 by jetan             #+#    #+#             */
/*   Updated: 2024/05/29 16:45:03 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_distance(t_stack_node **stack, int index)
{
	t_stack_node	*node;
	int	distance;
	
	node = *stack;
	distance = 0;
	while (node)
	{
		if (node->index == index)
			break ;
		distance++;
		node = node->next;
	}
	return (distance);
}

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;
	
	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a);
	else if ((*a)->next == biggest_node)
		rra(a);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int distance;
	
	if (stack_sorted(*a) == 1)
		return ;
	distance = get_distance(a, get_min(a, -1));
	printf("DIST: %d\n", distance);
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
		rra(a);
	if (stack_sorted(*a) == 1)
		return ;
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	distance;
	
	distance = get_distance(a, get_min(a, -1));
	if (distance == 1)
		ra(a);
	else if (distance == 2)
	{
		ra(a);
		ra(a);
	}
	else if (distance == 3)
	{
		rra(a);
		rra(a);
	}
	else if (distance == 4)
		rra(a);
	if (stack_sorted(*a) == 1)
		return ;
	pb(a, b);
	sort_four(a, b);
	pa(a, b);
}

void	sort_small_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else if (stack_len(*a) == 5)
		sort_five(a, b);
}