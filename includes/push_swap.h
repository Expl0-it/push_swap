/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:51:07 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/28 12:58:02 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

// INCLUDES
# include <stdlib.h>
# include "../libft/libft.h"
// TODO: DLEATE LATER AFTER ADDING PRINTF TO LIBFT
# include "../ft_printf/includes/ft_printf.h"

enum	e_errors
{
	OK = 0,
	NOT_ENOUGH_ARGUMENTS = 1,
	SYNTAX_ERROR = 2,
	INT_OVERFLOW = 3,
	NUMBER_REPETITION = 4,
	MALLOC_ERROR = 5
};

typedef struct s_db_list
{
	int					value;
	struct s_db_list	*next;
	struct s_db_list	*prev;
}				t_db_list;

// FUNCTION DELARATIONS

// stack init.c
long		ft_atol(const char *nptr);
void		stack_init(t_db_list **a, char **argv, bool is_argc_2);

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
void		db_lstadd_back(t_db_list **lst, t_db_list *element);

// error_free.c
bool		error_syntax(char *str_nb);
bool		error_repetition(t_db_list *a, int nbr);
void		free_stack(t_db_list **stack);
void		free_split(char **argv);
void		error_free(t_db_list **a, char **argv, bool is_argc_2, int code);

#endif
