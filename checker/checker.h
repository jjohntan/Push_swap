/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jetan <jetan@student.42kl.edu.my>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 14:55:03 by jetan             #+#    #+#             */
/*   Updated: 2024/05/24 13:33:55 by jetan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include "../inc/push_swap.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

//get_next_line
char	*get_next_line(int fd);
char	*ft_read(int fd, char *res);
char	*ft_line(char *buffer);
char	*ft_next(char *buffer);
char	*ft_strjoin(char *s1, char *s2);
size_t	ft_strlen(const char *s);
char	*ft_strchr(const char *s, int c);
void	*ft_calloc(size_t elementCount, size_t elementSize);
void	ft_bzero(void *s, size_t n);

//checker
int		ft_strcmp(char *s1, char *s2);
void	error(t_stack_node **a, t_stack_node **b);
void	parse_command(t_stack_node **a, t_stack_node **b, char *command);

#endif