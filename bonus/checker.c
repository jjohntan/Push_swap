/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:00:39 by jetan             #+#    #+#             */
/*   Updated: 2024/05/30 14:59:18 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/checker.h"

int	ft_strcmp(char *s1, char *s2)
{
	while (*s1 || *s2)
	{
		if (*s1 != *s2)	
			return (*s1 - *s2);
		s1++;
		s2++;
	}
	return (0);
}

void	error(t_stack_node **a, t_stack_node **b)
{
	free_stack(a);
	free_stack(b);
	write(2, "Error\n", 6);
	exit(1);
}

void	parse_command(t_stack_node **a, t_stack_node **b, char *command)
{
	if (ft_strcmp(command, "pa\n"))
		pa(a, b);
	else if (ft_strcmp(command, "pb\n"))
		pb(b, a);
	else if (ft_strcmp(command, "rra"))
		rra(a);
	else if (ft_strcmp(command, "rrb\n"))
		rrb(b);
	else if (ft_strcmp(command, "rrr\n"))
		rrr(a, b);
	else if (ft_strcmp(command, "ra\n"))
		ra(a);
	else if (ft_strcmp(command, "rb\n"))
		rb(b);
	else if (ft_strcmp(command, "rr\n"))
		rr(a, b);
	else if (ft_strcmp(command, "sa\n"))
		sa(a);
	else if (ft_strcmp(command, "sb\n"))
		sb(b);
	else if (ft_strcmp(command, "ss\n"))
		ss(a, b);
	else
		error(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**input;
	char	*next_line;

	a = NULL;
	b = NULL;
	input = parsing(ac, av);
	init_stack(&a, input);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}