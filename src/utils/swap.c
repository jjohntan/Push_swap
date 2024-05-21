/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 17:02:59 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 20:00:56 by jetan            ###   ########.fr       */
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
void	print_list(t_stack_node **stack)
{
	t_stack_node *buffer;
	
	buffer = *stack;
	while (*stack != NULL)
	{
		printf("%d\n", (*stack)->nbr);
		*stack = (*stack)->next;
	}
	*stack = buffer;
}

int main() {
    t_stack_node *stack_a = NULL;
    t_stack_node *stack_b = NULL;

    t_stack_node *node1 = malloc(sizeof(t_stack_node));
    node1->nbr = 1;
    node1->next = NULL;
    node1->previous = NULL;
    stack_a = node1;

    t_stack_node *node2 = malloc(sizeof(t_stack_node));
    node2->nbr = 2;
    node2->next = NULL;
    node2->previous = NULL;
    stack_b = node2;

	printf("stack_a:\n");
	print_list(&stack_a);
	printf("stack_b:\n");
	print_list(&stack_b);
	printf("after ");
	pa(&stack_a, &stack_b);
	printf("stack_a:\n");
	print_list(&stack_a);
	printf("stack_b:\n");
	print_list(&stack_b);

    return 0;
}