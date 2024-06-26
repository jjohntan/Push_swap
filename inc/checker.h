/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:52:22 by jetan             #+#    #+#             */
/*   Updated: 2024/06/06 16:47:41 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "../libft/libft.h"
# include "../bonus/get_next_line_bonus.h"
# include <limits.h>
# include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

//error_free
void			free_stack(t_stack_node **stack);
int				error_syntax(char *stack);
int				error_duplicate(t_stack_node *stack);
void			free_error(t_stack_node **a);
void			free_input(char **input);

//stack node initiation
void			init_stack(t_stack_node **a, char **av);
char			**parsing(int ac, char **av);
void			append_node(t_stack_node **stack, int n);
void			index_stack(t_stack_node **a);

//stack utilities
int				stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node	*stack);
int				get_min_index(t_stack_node **stack, int value);
void			*get_min_node(t_stack_node **a);
int				get_max_bits(t_stack_node **a);
int				get_distance(t_stack_node **stack, int index);

//operations
void			push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b, int print);
void			pb(t_stack_node **a, t_stack_node **b, int print);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a, int print);
void			rrb(t_stack_node **b, int print);
void			rrr(t_stack_node **a, t_stack_node **b, int print);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a, int print);
void			rb(t_stack_node **b, int print);
void			rr(t_stack_node **a, t_stack_node **b, int print);
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a, int print);
void			sb(t_stack_node **b, int print);
void			ss(t_stack_node **a, t_stack_node **b, int print);

//algorithm
void			push_swap(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);
void			sort_four(t_stack_node **a, t_stack_node **b);
void			sort_small_stack(t_stack_node **a, t_stack_node **b);

#endif
