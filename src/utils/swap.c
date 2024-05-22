/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:02:59 by jetan             #+#    #+#             */
/*   Updated: 2024/05/22 15:56:53 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node *first;
	t_stack_node *second;
	
	if (!*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	second->previous = NULL;
	first->previous = second;
	if (second->next == NULL)
	{
		first->next = NULL;
		second->next = first;
	}
	else
	{
		first->next = second->next;
		second->next = first;
		first->next->previous = first;
	}
	*stack = second;
}

void	sa(t_stack_node **a)
{
	swap(a);
	ft_printf("sa\n");
}

void	sb(t_stack_node **b)
{
	swap(b);
	ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_printf("ss\n");
}