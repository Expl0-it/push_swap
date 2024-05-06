/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/05 21:53:42 by mamichal         ###   ########.fr       */
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
		ft_printf("rra\n");
}

void	rrb(t_stack *b, bool checker)
{
	reverse_rotate(&b->node);
	if (!checker)
		ft_printf("rrb\n");
}

void	rrr(t_stack *a, t_stack *b, bool checker)
{
	reverse_rotate(&a->node);
	reverse_rotate(&b->node);
	if (!checker)
		ft_printf("rrr\n");
}
