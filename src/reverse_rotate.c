/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/02 19:26:45 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	reverse_rotate(t_db_list **node)
{
	t_db_list	*last_node;

	if (NULL == node || NULL == *node || NULL == (*node)->next)
		return ;
	last_node = db_lstlast(*node);
	last_node->prev->next = NULL;
	last_node->prev = NULL;
	last_node->next = *node;
	last_node->next->prev = last_node;
	*node = last_node;
}

void	rra(t_stack *a, bool checker)
{
	reverse_rotate(&a->node);
	if (!checker)
		write(1, "rra\n", 4);
}

void	rrb(t_stack *b, bool checker)
{
	reverse_rotate(&b->node);
	if (!checker)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack *a, t_stack *b, bool checker)
{
	reverse_rotate(&a->node);
	reverse_rotate(&b->node);
	if (!checker)
		write(1, "rrr\n", 4);
}
