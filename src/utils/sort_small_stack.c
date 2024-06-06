/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_stack.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/25 20:33:53 by jetan             #+#    #+#             */
/*   Updated: 2024/06/05 15:05:41 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sort_three(t_stack_node **a)
{
	t_stack_node	*biggest_node;

	biggest_node = find_max(*a);
	if (*a == biggest_node)
		ra(a, 1);
	else if ((*a)->next == biggest_node)
		rra(a, 1);
	if ((*a)->nbr > (*a)->next->nbr)
		sa(a, 1);
}

void	sort_four(t_stack_node **a, t_stack_node **b)
{
	int	distance;

	if (stack_sorted(*a) == 1)
		return ;
	distance = get_distance(a, get_min_index(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
		rra(a, 1);
	if (stack_sorted(*a) == 1)
		return ;
	pb(a, b, 1);
	sort_three(a);
	pa(a, b, 1);
}

void	sort_five(t_stack_node **a, t_stack_node **b)
{
	int	distance;

	distance = get_distance(a, get_min_index(a, -1));
	if (distance == 1)
		ra(a, 1);
	else if (distance == 2)
	{
		ra(a, 1);
		ra(a, 1);
	}
	else if (distance == 3)
	{
		rra(a, 1);
		rra(a, 1);
	}
	else if (distance == 4)
		rra(a, 1);
	if (stack_sorted(*a) == 1)
		return ;
	pb(a, b, 1);
	sort_four(a, b);
	pa(a, b, 1);
}

void	sort_small_stack(t_stack_node **a, t_stack_node **b)
{
	if (stack_len(*a) == 2)
		sa(a, 1);
	else if (stack_len(*a) == 3)
		sort_three(a);
	else if (stack_len(*a) == 4)
		sort_four(a, b);
	else if (stack_len(*a) == 5)
		sort_five(a, b);
}
