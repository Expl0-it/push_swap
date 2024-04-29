/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/29 13:37:12 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_db_list **stack)
{
	t_db_list	*last_node;

	if (NULL == stack || NULL == *stack || NULL == (*stack)->next)
		return ;
	last_node = db_lstlast(*stack);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *stack;
	last_node->next->prev = last_node;
	*stack = last_node;
}

void	rra(t_db_list **a, bool checker)
{
	reverse_rotate(a);
	if (!checker)
		ft_printf("rra\n");
}

void	rrb(t_db_list **b, bool checker)
{
	reverse_rotate(b);
	if (!checker)
		ft_printf("rrb\n");
}

void	rrr(t_db_list **a, t_db_list **b, bool checker)
{
	reverse_rotate(a);
	reverse_rotate(b);
	if (!checker)
		ft_printf("rrr\n");
}
