/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/27 22:20:12 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/05 21:53:11 by mamichal         ###   ########.fr       */
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
		ft_printf("ra\n");
}

void	rb(t_stack *b, bool checker)
{
	rotate(&b->node);
	if (!checker)
		ft_printf("rb\n");
}

void	rr(t_stack *a, t_stack *b, bool checker)
{
	rotate(&a->node);
	rotate(&b->node);
	if (!checker)
		ft_printf("rr\n");
}
