/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_init.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:22:30 by jetan             #+#    #+#             */
/*   Updated: 2024/05/22 16:04:17 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_current_index(t_stack_node *stack)
{
	int	i;
	int	median;
	
	if (!stack)
		return ;
	i = 0;
	median = stack_len(stack) / 2;
	while (stack)
	{
		stack->index = i;
		if (i >= median)
			stack->above_median = true;
		else
			stack->above_median = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_node(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*ptr_a;
	t_stack_node	*target_node;
	long			best_value;
	
	while (b)
	{
		ptr_a = a;
		best_value = LONG_MAX;
		while (ptr_a)
		{
			if (ptr_a->nbr > b->nbr && ptr_a->nbr < best_value)
			{
				best_value = ptr_a->nbr;
				target_node = ptr_a;
			}
			ptr_a = ptr_a->next;
		}
		if (best_value == LONG_MAX)
			b->target_node = find_min(a);
		else
			b->target_node = target_node;
		b = b->next;
	}
}

void	set_cost(t_stack_node *a, t_stack_node *b)
{
	int	len_a;
	int	len_b;
	
	len_a = stack_len(a);
	len_b = stack_len(b);
	
	while(b)
	{
		b->push_cost = b->index;
		if (!b->above_median)
			b->push_cost = len_b - b->index;
		if (b->target_node->above_median)
			b->push_cost += b->target_node->index;
		else
			b->push_cost += len_a - (b->target_node->index);
		b = b->next;
	}
}

void	set_cheapest(t_stack_node *stack)
{
	long	cheapest_value;
	t_stack_node	*cheapest_node;
	
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_node = stack;
			cheapest_value = stack->push_cost;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}

void	init_nodes(t_stack_node *a, t_stack_node *b)
{
	set_current_index(a);
	set_current_index(b);
	set_target_node(a, b);
	set_cost(a, b);
	set_cheapest(b);
}