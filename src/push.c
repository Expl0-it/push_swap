/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:47:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/19 17:01:14 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

// NOTE: (*src).node === src->node ('->' is a dereference and access combined)
static void	push(t_stack *dst, t_stack *src)
{
	t_db_list	*tmp;

	if (NULL == src->node)
		return ;
	tmp = src->node;
	src->node = src->node->next;
	if (src->node)
		src->node->prev = NULL;
	tmp->prev = NULL;
	if (NULL == dst->node)
	{
		tmp->next = NULL;
		dst->node = tmp;
	}
	else
	{
		tmp->next = dst->node;
		tmp->next->prev = tmp;
		dst->node = tmp;
	}
	src->size = (src->size) - 1;
	dst->size = (dst->size) + 1;
}

void	pa(t_stack *a, t_stack *b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_stack *b, t_stack *a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
