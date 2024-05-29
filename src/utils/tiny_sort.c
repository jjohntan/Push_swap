/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:00:19 by jetan             #+#    #+#             */
/*   Updated: 2024/05/27 16:26:22 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	show_both_stacks(t_stack_node **a, t_stack_node **b)
{
	ft_printf("StackA: \n");
	print_list(a);
	ft_printf("StackB: \n");
	print_list(b);
}


// void	sort_three(t_stack_node **a)
// {
// 	t_stack_node	*biggest_node;

// 	biggest_node = find_max(*a);
// 	if (*a == biggest_node)
// 		ra(a);
// 	else if ((*a)->next == biggest_node)
// 		rra(a);
// 	if ((*a)->nbr > (*a)->next->nbr)
// 		sa(a);
// }

// void	sort_five(t_stack_node **a, t_stack_node **b)
// {
// 	while (stack_len(*a) > 3)
// 	{
// 		init_nodes(*a, *b);
// 		finish_rotation(a, find_min(*a), 'a');
// 		pb(a, b);
// 		show_both_stcaks(a, b);
// 		if (!*b)
// 			exit(0);
// 	}
// }
