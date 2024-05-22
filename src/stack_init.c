/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:11 by jetan             #+#    #+#             */
/*   Updated: 2024/05/22 17:45:10 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	append_node(t_stack_node **stack,int nbr)
{
	t_stack_node	*node;
	t_stack_node	*last_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack_node));
	if (!node)
		return ;
	node->nbr = nbr;
	node->next = NULL;
	if (!(*stack))
	{
		*stack = node;
		node->previous = NULL;
	}
	else
	{
		last_node = find_last(*stack);
		last_node->next = node;
		node->previous = last_node;
	}
}

void	init_stack(t_stack_node **a, char **av)
{
	int		i;
	long	n;
	
	i = 0;
	while (av[++i])
	{
		if (error_syntax(av[i]))
			free_error(a);
		n = ft_atol(av[i]);
		if (n < INT_MIN || n > INT_MAX)
			free_error(a);
		append_node(a, n);
	}
	if (error_duplicate(*a))
			free_error(a);
}

t_stack_node	*get_cheapest(t_stack_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}
// t_stack_node init_stack(void)
// {
// 	t_stack_node stack;
	
// 	stack.nbr = 0;
// 	return (stack);
// }

// void init_stack(t_stack_node *stack)
// {
// 	stack->nbr = 0;
// }

// t_stack_node stack;

// stack = init_stack();
// init_stack(&stack);

// convert string to integer and pass to stack
//store all the int to a pointer

void	finish_rotation(t_stack_node **stack, t_stack_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (stack_name == 'a')
		{
			if (top_node->above_median)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->above_median)
				rb(stack);
			else
				rrb(stack);
		}
	}
}