/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_big_stack.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/26 19:01:46 by jetan             #+#    #+#             */
/*   Updated: 2024/06/03 15:01:33 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push_swap(t_stack_node **a, t_stack_node **b)
{
	t_stack_node	*node;
	int				max_bits;
	int				shift;
	int				element;
	int				len;

	node = *a;
	len = stack_len(node);
	max_bits = get_max_bits(a);
	shift = -1;
	while (++shift < max_bits)
	{
		element = -1;
		while (++element < len)
		{
			node = *a;
			if ((node->index >> shift) & 1)
				ra(a);
			else
				pb(a, b);
		}
		while (stack_len(*b) != 0)
			pa(a, b);
	}
}
