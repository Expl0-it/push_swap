/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:24:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/01 14:49:30 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	stack_is_sorted(t_db_list *node)
{
	if (NULL == node)
		return (true);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}

void	stack_set_sizes(t_stack *a, t_stack *b)
{
	(*a).size = db_lstsize((*a).node);
	(*b).size = 0;
}

t_db_list	*return_cheapest(t_stack stack)
{
	if (NULL == stack.node)
		return (NULL);
	while (stack.node)
	{
		if (stack.node->utils.cheapest)
			return (stack.node);
		stack.node = stack.node->next;
	}
	return (NULL);
}
