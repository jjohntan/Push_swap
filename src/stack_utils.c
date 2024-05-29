/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:16:42 by jetan             #+#    #+#             */
/*   Updated: 2024/05/29 16:43:54 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	stack_sorted(t_stack_node *stack)
{
	if (!stack)
		return (1);
	while (stack->next)
	{
		if (stack->nbr > stack->next->nbr)
			return (0);
		stack = stack->next;
	}
	return (1);
}

int	stack_len(t_stack_node *stack)
{
	int	i;

	if (!stack)
		return (0);
	i = 0;
	while (stack)
	{
		stack = stack->next;
		i++;
	}
	return (i);
}

t_stack_node	*find_last(t_stack_node *stack)
{
	t_stack_node	*node;

	if (!stack)
		return (0);
	node = stack;
	while (node->next)
		node = node->next;
	return (node);
}

// t_stack_node	*find_min(t_stack_node *stack)
// {
// 	t_stack_node	*min_node;
// 	long			min;

// 	if (!stack)
// 		return (NULL);
// 	min = LONG_MAX;
// 	while (stack)
// 	{
// 		if (stack->nbr < min)
// 		{
// 			min = stack->nbr;
// 			min_node = stack;
// 		}
// 		stack = stack->next;
// 	}
// 	return (min_node);
// }

int	get_min(t_stack_node **stack, int value)
{
	t_stack_node	*node; 
	int	min_index;
	
	node = *stack;
	min_index = node->index;
	while (node->next)
	{
		node = node->next;
		if ((node->index < min_index) && node->index != value)
			min_index = node->index;
	}
	return (min_index);
}

t_stack_node	*find_max(t_stack_node	*stack)
{
	t_stack_node	*max_node;
	long			max;

	if (!stack)
		return (NULL);
	max = LONG_MIN;
	while (stack)
	{
		if (stack->nbr > max)
		{
			max = stack->nbr;
			max_node = stack;
		}
		stack = stack->next;
	}
	return (max_node);
}
