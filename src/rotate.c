/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/02 19:29:35 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	rotate(t_db_list **node)
{
	t_db_list	*last_node;

	if (NULL == node || NULL == *node || NULL == (*node)->next)
		return ;
	last_node = db_lstlast(*node);
	last_node->next = *node;
	*node = (*node)->next;
	(*node)->prev = NULL;
	last_node->next->prev = last_node;
	last_node->next->next = NULL;
}

void	ra(t_stack *a, bool checker)
{
	rotate(&a->node);
	if (!checker)
		write(1, "ra\n", 3);
}

void	rb(t_stack *b, bool checker)
{
	rotate(&b->node);
	if (!checker)
		write(1, "rb\n", 3);
}

void	rr(t_stack *a, t_stack *b, bool checker)
{
	rotate(&a->node);
	rotate(&b->node);
	if (!checker)
		write(1, "rr\n", 3);
}
