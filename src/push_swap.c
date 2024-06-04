/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 15:24:01 by jetan             #+#    #+#             */
/*   Updated: 2024/06/04 10:49:31 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

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
