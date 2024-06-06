/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:02:59 by jetan             #+#    #+#             */
/*   Updated: 2024/06/05 15:09:16 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swap(t_stack_node **stack)
{
	t_stack_node	*first_node;
	t_stack_node	*second_node;

	if (!*stack || !(*stack)->next)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	second_node->previous = NULL;
	first_node->previous = second_node;
	if (second_node->next == NULL)
	{
		first_node->next = NULL;
		second_node->next = first_node;
	}
	else
	{
		first_node->next = second_node->next;
		second_node->next = first_node;
		first_node->next->previous = first_node;
	}
	*stack = second_node;
}

void	sa(t_stack_node **a, int print)
{
	swap(a);
	if (print == 1)
		ft_printf("sa\n");
}

void	sb(t_stack_node **b, int print)
{
	swap(b);
	if (print == 1)
		ft_printf("sb\n");
}

void	ss(t_stack_node **a, t_stack_node **b, int print)
{
	swap(a);
	swap(b);
	if (print == 1)
		ft_printf("ss\n");
}
