/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 16:28:04 by jetan             #+#    #+#             */
/*   Updated: 2024/06/05 15:13:03 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	reverse_rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	last_node->previous->next = NULL;
	last_node->previous = NULL;
	*stack = last_node;
}

void	rra(t_stack_node **a, int print)
{
	reverse_rotate(a);
	if (print == 1)
		ft_printf("rra\n");
}

void	rrb(t_stack_node **b, int print)
{
	reverse_rotate(b);
	if (print == 1)
		ft_printf("rrb\n");
}

void	rrr(t_stack_node **a, t_stack_node **b, int print)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (print == 1)
		ft_printf("rrr\n");
}
