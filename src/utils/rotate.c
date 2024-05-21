/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 17:12:39 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 19:49:06 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	rotate(t_stack_node **stack)
{
	t_stack_node	*last;
	
	if (!*stack || !(*stack)->next)
		return ;
	last = last_node(*stack);
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