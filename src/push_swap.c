/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:24:01 by jetan             #+#    #+#             */
/*   Updated: 2024/05/30 18:27:04 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	print_list(t_stack_node **stack)
{
	t_stack_node *buffer;
	
	buffer = *stack;
	while (*stack != NULL)
	{
		ft_printf("%d\n", (*stack)->nbr);
		*stack = (*stack)->next;
	}
	*stack = buffer;
}

int	list_count(t_stack_node **stack)
{
	t_stack_node *buffer;
	int count;

	count = 0;
	buffer = *stack;
	while (*stack != NULL)
	{
		count++;
		*stack = (*stack)->next;
	}
	*stack = buffer;
	return (count);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**input;
	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	input = parsing(ac, av);
	init_stack(&a, input);
	if (ac == 2)
		free_input(input);
	if (!stack_sorted(a))
	{
		if (stack_len(a) <= 5)
			sort_small_stack(&a, &b);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
