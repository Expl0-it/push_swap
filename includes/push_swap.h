/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/20 22:16:35 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include <stdlib.h>
# include "../libft/libft.h"

enum	e_errors
{
	NOT_ENOUGH_ARGUMENTS = -1,
	SYNTAX_ERROR = -2,
	INT_OVERFLOW = -3,
	NUMBER_REPETITION = -4
};

typedef struct s_stack_node
{
	int					value;
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
}				t_stack_node;

// FUNCTION DELARATIONS

// stack init.c
long	ft_atol(const char *nptr);
void	stack_init(t_stack_node **a, char **argv, bool is_argc_2);

// error_free.c
bool	error_syntax(char *str_nb);
bool	error_repetition(t_stack_node *a, int nbr);
void	free_stack(t_stack_node **stack);
void	free_split(char **argv);
void	error_free(t_stack_node **a, char **argv, bool is_argc_2, int code);

#endif
