/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:54:16 by jetan             #+#    #+#             */
/*   Updated: 2024/06/06 11:48:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	get_min_index(t_stack_node **stack, int value)
{
	t_stack_node	*node;
	int				min_index;

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

void	*get_min_node(t_stack_node **a)
{
	t_stack_node	*min_node;
	t_stack_node	*moving_node;
	int				min_found;

	min_node = NULL;
	min_found = 0;
	moving_node = *a;
	while (moving_node)
	{
		if ((moving_node->index == -1) && (min_found == 0
				|| moving_node->nbr < min_node->nbr))
		{
			min_node = moving_node;
			min_found = 1;
		}
		moving_node = moving_node->next;
	}
	return (min_node);
}

int	get_max_bits(t_stack_node **a)
{
	t_stack_node	*moving_node;
	int				max_index;
	int				max_bits;

	moving_node = *a;
	max_index = moving_node->index;
	max_bits = 0;
	while (moving_node)
	{
		if (moving_node->index > max_index)
			max_index = moving_node->index;
		moving_node = moving_node->next;
	}
	while (max_index != 0)
	{
		max_index = max_index / 2;
		max_bits++;
	}
	return (max_bits);
}

int	get_distance(t_stack_node **stack, int index)
{
	t_stack_node	*node;
	int				distance;

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
// void	print_list(t_stack_node **stack)
// {
// 	t_stack_node *buffer;
//	
// 	buffer = *stack;
// 	while (*stack != NULL)
// 	{
// 		printf("%d\n", (*stack)->nbr);
// 		*stack = (*stack)->next;
// 	}
// 	*stack = buffer;
// }