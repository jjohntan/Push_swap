/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 10:00:39 by jetan             #+#    #+#             */
/*   Updated: 2024/06/06 09:22:24 by jetan            ###   ########.fr       */
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
	if (!ft_strcmp(command, "pa\n"))
		pa(a, b, 0);
	else if (!ft_strcmp(command, "rra\n"))
		rra(a, 0);
	else if (!ft_strcmp(command, "rrb\n"))
		rrb(b, 0);
	else if (!ft_strcmp(command, "rrr\n"))
		rrr(a, b, 0);
	else if (!ft_strcmp(command, "ra\n"))
		ra(a, 0);
	else if (!ft_strcmp(command, "rb\n"))
		rb(b, 0);
	else if (!ft_strcmp(command, "rr\n"))
		rr(a, b, 0);
	else if (!ft_strcmp(command, "sa\n"))
		sa(a, 0);
	else if (!ft_strcmp(command, "sb\n"))
		sb(b, 0);
	else if (!ft_strcmp(command, "ss\n"))
		ss(a, b, 0);
	else
		error(a, b);
}

int	main(int ac, char **av)
{
	t_stack_node	*a;
	t_stack_node	*b;
	char			**input;
	char			*next_line;
	int				len;

	if (ac < 2)
		return (0);
	a = NULL;
	b = NULL;
	input = parsing(ac, av);
	init_stack(&a, input);
	len = stack_len(a);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		parse_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_sorted(a) && stack_len(a) == len)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_stack(&a);
}
