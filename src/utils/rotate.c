/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:12:39 by jetan             #+#    #+#             */
/*   Updated: 2024/05/22 15:57:43 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	
	if (!*stack || !(*stack)->next)
		return ;
	last = find_last(*stack);
	(*stack)->next = NULL;
	(*stack)->previous = last;
	*stack = (*stack)->next;
	(*stack)->previous = NULL;
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