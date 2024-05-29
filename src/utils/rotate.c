/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:12:39 by jetan             #+#    #+#             */
/*   Updated: 2024/05/29 18:09:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

// void	rotate(t_stack_node **stack)
// {
// 	t_stack_node	*last_node;
// 	t_stack_node	*second_node;

// 	if (!*stack || !(*stack)->next)
// 		return ;
// 	last_node = find_last(*stack);
// 	second_node = (*stack)->next;
// 	*stack = second_node;
// 	second_node->previous->next = NULL;
// 	second_node->previous->previous = last_node;
// 	last_node->next = second_node->previous;
// 	second_node->previous = NULL;
// }

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last_node;

	if (!*stack || !(*stack)->next)
		return ;
	last_node = find_last(*stack);
	last_node->next = *stack;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
	last_node->next->previous = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack_node **a)
{
	rotate(a);
	ft_printf("ra\n");
}

void	rb(t_stack_node **b)
{
	rotate(b);
	ft_printf("rb\n");
}

void	rr(t_stack_node **a, t_stack_node **b)
{
	rotate(a);
	rotate(b);
	ft_printf("rr\n");
}
