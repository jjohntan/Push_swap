/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 09:52:22 by jetan             #+#    #+#             */
/*   Updated: 2024/05/28 16:59:58 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdbool.h>
# include <limits.h>
#include <stdio.h>

typedef struct s_stack_node
{
	int					nbr;
	int					index; 
	int					push_cost;
	bool				above_median;
	bool				cheapest;
	struct s_stack_node	*target_node;
	struct s_stack_node	*next;
	struct s_stack_node	*previous;
}	t_stack_node;

//error
void			free_stack(t_stack_node **stack);
int				error_syntax(char *stack);
int				error_duplicate(t_stack_node *stack);
void			free_error(t_stack_node **a);
//node initiation
void			init_stack(t_stack_node **a, char **av);
t_stack_node	*get_cheapest(t_stack_node *stack);
void			set_current_index(t_stack_node *stack);
void			set_target_node(t_stack_node *a, t_stack_node *b);
void			set_cost(t_stack_node *a, t_stack_node *b);
void			set_cheapest(t_stack_node *stack);
void			init_nodes(t_stack_node *a, t_stack_node *b);
//stack initiation
char			**parsing(int ac, char **av);
void			append_node(t_stack_node **stack, int n);
void			finish_rotation(t_stack_node **stack,
					t_stack_node *top_node, char stack_name);
//stack utilities
int			stack_sorted(t_stack_node *stack);
int				stack_len(t_stack_node *stack);
t_stack_node	*find_last(t_stack_node *stack);
t_stack_node	*find_min(t_stack_node *stack);
t_stack_node	*find_max(t_stack_node	*stack);
//operations
void			push(t_stack_node **dst, t_stack_node **src);
void			pa(t_stack_node **a, t_stack_node **b);
void			pb(t_stack_node **a, t_stack_node **b);
void			reverse_rotate(t_stack_node **stack);
void			rra(t_stack_node **a);
void			rrb(t_stack_node **b);
void			rrr(t_stack_node **a, t_stack_node **b);
void			rotate(t_stack_node **stack);
void			ra(t_stack_node **a);
void			rb(t_stack_node **b);
void			rr(t_stack_node **a, t_stack_node **b);
void			swap(t_stack_node **stack);
void			sa(t_stack_node **a);
void			sb(t_stack_node **b);
void			ss(t_stack_node **a, t_stack_node **b);
//
void			rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			rev_rotate_both(t_stack_node **a,
					t_stack_node **b, t_stack_node *cheapest_node);
void			move_nodes(t_stack_node **a, t_stack_node **b);
void			push_swap(t_stack_node **a, t_stack_node **b);
void			sort_three(t_stack_node **a);
void			sort_five(t_stack_node **a, t_stack_node **b);

void	print_list(t_stack_node **stack);
void	show_both_stacks(t_stack_node **a, t_stack_node **b);

//new
void	sort_four(t_stack_node **a, t_stack_node **b);
void	sort_small_stack(t_stack_node **a, t_stack_node **b);
int	get_min(t_stack_node **stack, int value);
void	*get_next_min(t_stack_node **a);
void	index_stack(t_stack_node **a);
int	get_max_bits(t_stack_node **a);
#endif
