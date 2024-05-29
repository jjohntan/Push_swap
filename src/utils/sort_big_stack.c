/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:01:46 by jetan             #+#    #+#             */
/*   Updated: 2024/05/29 16:11:18 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"
#include <stdio.h>
void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	int				max_bits;
	int				shift;
	int				element;
	
	node = *a;
	max_bits = 0;
	while (stack_len(*a) >> max_bits != 0)
		max_bits++;
	// while (find_max(*a)->index >> max_bits != 0)
	// 	max_bits++;
	// max_bits = get_max_bits(a);
	shift = -1;
	int len = stack_len(node);
	while (++shift < max_bits)
	{
		element = -1;
		while (++element < len)
		{
			node = *a;
			if (((node->index >> shift) & 1) == 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_len(*b) != 0)
		{
			pa(a, b);
		}
	}
}

int	get_max_bits(t_stack_node **a)
{
	t_stack_node	*moving_node;
	int			max_index;
	int			max_bits;

	moving_node = *a;
	max_index = moving_node->index;
	max_bits = 0;
	while (moving_node)
	{
		if (moving_node->index > max_index)
			max_index = moving_node->index;
		moving_node = moving_node->next;
	}
	while ((max_index >> max_bits) != 0)
		max_bits++;
	return (max_bits);
}
