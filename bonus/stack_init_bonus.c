/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 17:19:11 by jetan             #+#    #+#             */
/*   Updated: 2024/06/05 10:49:09 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

char	**parsing(int ac, char **av)
{
	int	flag;

	if (ft_strlen(av[1]) == 0)
		write (2, "Error\n", 6);
	if (ac == 1 || (ac == 2 && !av[1][0]))
		return (NULL);
	else if (ac == 2)
	{
		av = ft_split(av[1], ' ');
		flag = 0;
	}
	else
		flag = 1;
	return (av + flag);
}

void	append_node(t_stack_node **stack, int nbr)
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
	node->index = -1;
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

	if (av == NULL)
		return ;
	i = -1;
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
	index_stack(a);
}

void	index_stack(t_stack_node **a)
{
	t_stack_node	*current_min_node;
	int				index;

	index = 0;
	current_min_node = get_min_node(a);
	while (current_min_node)
	{
		current_min_node->index = index++;
		current_min_node = get_min_node(a);
	}
}
