/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/29 10:48:32 by jetan             #+#    #+#             */
/*   Updated: 2024/06/06 18:29:17 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

void	free_stack(t_stack_node **stack)
{
	t_stack_node	*temp;
	t_stack_node	*current_node;

	if (!stack)
		return ;
	current_node = *stack;
	while (current_node)
	{
		temp = current_node->next;
		free(current_node);
		current_node = temp;
	}
}

int	error_syntax(char *stack)
{
	if (!(*stack == '-' || *stack == '+'
			|| (*stack >= '0' && *stack <= '9')))
		return (1);
	if ((*stack == '+' || *stack == '-')
		&& !(stack[1] >= '0' && stack[1] <= '9'))
		return (1);
	while (*++stack)
	{
		if (!(*stack >= '0' && *stack <= '9'))
			return (1);
	}
	return (0);
}

int	error_duplicate(t_stack_node *stack)
{
	t_stack_node	*current_node;
	t_stack_node	*next_node;

	if (!stack)
		return (0);
	current_node = stack;
	while (current_node)
	{
		next_node = current_node->next;
		while (next_node)
		{
			if (current_node->nbr == next_node->nbr)
				return (1);
			next_node = next_node->next;
		}
		current_node = current_node->next;
	}
	return (0);
}

void	free_error(t_stack_node **a)
{
	free_stack(a);
	write(2, "Error\n", 6);
	exit(1);
}

void	free_input(char **input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		free(input[i]);
		i++;
	}
	free(input);
}
