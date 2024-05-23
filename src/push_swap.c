/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:24:01 by jetan             #+#    #+#             */
/*   Updated: 2024/05/23 16:57:46 by jetan            ###   ########.fr       */
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

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**input;

	a = NULL;
	b = NULL;
	input = passing(ac, av);
	init_stack(&a, input);
	print_list(&a);
	if (!stack_sorted(a))
	{
		if (stack_len(a) == 2)
			sa(&a);
		else if (stack_len(a) == 3)
			sort_three(&a);
		else
			push_swap(&a, &b);
	}
	free_stack(&a);
}
