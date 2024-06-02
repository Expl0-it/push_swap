/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:20:18 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/02 19:30:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_db_list	**node)
{
	if (NULL == *node || NULL == node || NULL == (*node)->next)
		return ;
	*node = (*node)->next;
	(*node)->prev->prev = *node;
	(*node)->prev->next = (*node)->next;
	if (NULL != (*node)->next)
		(*node)->next->prev = (*node)->prev;
	(*node)->next = (*node)->prev;
	(*node)->prev = NULL;
}

void	sa(t_stack *a, bool checker)
{
	swap(&a->node);
	if (!checker)
		write(1, "sa\n", 3);
}

void	sb(t_stack *b, bool checker)
{
	swap(&b->node);
	if (!checker)
		write(1, "sb\n", 3);
}

void	ss(t_stack *a, t_stack *b, bool checker)
{
	swap(&a->node);
	swap(&b->node);
	if (!checker)
		write(1, "ss\n", 3);
}
