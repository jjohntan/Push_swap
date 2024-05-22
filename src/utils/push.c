/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/26 19:34:38 by jetan             #+#    #+#             */
/*   Updated: 2024/05/22 16:24:00 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	push(t_stack_node **dst, t_stack_node **src)
{
	t_stack_node *buffer;
	
	if (!*src)
		return ;
	buffer = *src;
	if ((*src)->next)
	{
		(*src)->previous = NULL;
		*src = (*src)->next;
	}
	buffer->previous = NULL;
	if (!*dst)
	{
		*dst = buffer;
	}
	else
	{
		buffer->next = *dst;
		buffer->previous = NULL;
		(*dst)->previous = buffer;
		*dst = buffer;
	}
}

void	pa(t_stack_node **a, t_stack_node **b)
{
	push(a, b);
	ft_printf("pa\n");//
}

void	pb(t_stack_node **a, t_stack_node **b)
{
	push(b, a);
	ft_printf("pb\n");//
}
// void	print_list(t_stack_node **stack)
// {
// 	t_stack_node *buffer;
	
// 	buffer = *stack;
// 	while (*stack != NULL)
// 	{
// 		printf("%d\n", (*stack)->nbr);
// 		*stack = (*stack)->next;
// 	}
// 	*stack = buffer;
// }

// int main() {
//     t_stack_node *stack_a = NULL;
//     t_stack_node *stack_b = NULL;

//     t_stack_node *node1 = malloc(sizeof(t_stack_node));
//     node1->nbr = 1;
//     node1->next = NULL;
//     node1->previous = NULL;
//     stack_a = node1;

//     t_stack_node *node2 = malloc(sizeof(t_stack_node));
//     node2->nbr = 2;
//     node2->next = NULL;
//     node2->previous = NULL;
//     stack_b = node2;

// 	printf("stack_a:\n");
// 	print_list(&stack_a);
// 	printf("stack_b:\n");
// 	print_list(&stack_b);
// 	printf("after ");
// 	pa(&stack_a, &stack_b);
// 	printf("stack_a:\n");
// 	print_list(&stack_a);
// 	printf("stack_b:\n");
// 	print_list(&stack_b);

//     return 0;
// }