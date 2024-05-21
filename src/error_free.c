/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:48:32 by jetan             #+#    #+#             */
/*   Updated: 2024/05/21 18:29:43 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node *temp;
	t_stack_node *current;
	
	if (!stack)
		return ;
	current = *stack;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}
int	error_syntax(char *stack)
{
	if (!(*stack == '-' || *stack == '+' || (*stack >= '0' && *stack <= '9')))
		return (1);
	if ((*stack == '+' || *stack == '-') && !(stack[1] >= '0' && stack[1] <= '9'))
		return (1);
	while (*stack)
	{
		if (!(*stack >= '0' && *stack <= '9'))
			return (1);
		stack++;
	}
	return (0);
}

int	error_duplicate(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next;
	
	if (!stack)
		return (0);
	current = stack;
	while (current)
	{
		next = current->next;
		while (next)
		{
			if (current->nbr == next->nbr)
				return (1);
			next++;
		}
		current++;
	}
	return (0);
}