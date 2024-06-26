/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/05 14:37:40 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <limits.h>
# include <stdbool.h>
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
//# include "../libft/includes/ft_printf.h"
# include "../libft/libft.h"

typedef enum e_errors
{
	OK = 0,
	NOT_ENOUGH_ARGUMENTS = 1,
	SYNTAX_ERROR = 2,
	INT_OVERFLOW = 3,
	NUMBER_REPETITION = 4,
	MALLOC_ERROR = 5
}				t_errors;

typedef struct s_ps_utils
{
	int					curr_pos;
	int					final_pos;
	int					price;
	bool				above_median;
	bool				cheapest;
	struct s_db_list	*target;
}				t_ps_utils;

typedef struct s_db_list
{
	int					value;
	struct s_db_list	*next;
	struct s_db_list	*prev;
	t_ps_utils			utils;
}				t_db_list;

typedef struct s_stack
{
	t_db_list	*node;
	int			size;
}				t_stack;

// FUNCTION DELARATIONS

// stack init.c
long		ft_atol(const char *nptr);
void		stack_init(t_stack *a, char **argv, bool is_argc_2);

// db_linked_list_utils.c
t_db_list	*db_lstnew(int value);
/*
 * @brief Show last node of a list
 *
 * Returns the last node of the list
 *
 * @param lst The beginning of the list
 * @return Last node of the list
*/
t_db_list	*db_lstlast(t_db_list *lst);
int			db_lstsize(t_db_list *lst);
void		db_lstadd_back(t_db_list **lst, t_db_list *element);
t_db_list	*find_smallest(t_db_list *node);

// error_free.c
bool		error_syntax(char *str_nb);
bool		error_repetition(t_db_list *a, int nbr);
void		free_stack_nodes(t_db_list **first_node);
void		free_split(char **argv);
void		error_free(t_db_list **a, char **argv, \
				bool is_argc_2, t_errors code);

// swap.c
void		sa(t_stack *a, bool checker);
void		sb(t_stack *b, bool checker);
void		ss(t_stack *a, t_stack *b, bool checker);

// push.c
void		pa(t_stack *a, t_stack *b, bool checker);
void		pb(t_stack *b, t_stack *a, bool checker);

// rotate.c
void		ra(t_stack *a, bool checker);
void		rb(t_stack *b, bool checker);
void		rr(t_stack *a, t_stack *b, bool checker);

// reverse_rotate.c
void		rra(t_stack *a, bool checker);
void		rrb(t_stack *b, bool checker);
void		rrr(t_stack *a, t_stack *b, bool checker);

// stack_utils.c
bool		stack_is_sorted(t_db_list *node);
void		stack_set_sizes(t_stack *a, t_stack *b);
t_db_list	*return_cheapest(t_stack stack);

// tiny_sort.c
void		tiny_sort(t_stack *a);
void		a_leave_three(t_stack *a, t_stack *b);

// init_node_utils.c
void		set_position(t_stack stack);
void		set_target(t_stack a, t_stack b);
void		set_price(t_stack a, t_stack b);
void		set_cheapest(t_stack stack);
void		init_list_utils(t_stack a, t_stack b);

// advanced_motions.c
void		put_node_on_top(t_stack *stack, \
				t_db_list *top_node, char stack_name);
void		move_nodes(t_stack *a, t_stack *b);

// push_swap.c
void		push_swap(t_stack *a, t_stack *b);

#endif
