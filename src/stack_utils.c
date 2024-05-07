/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:24:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/07 21:30:49 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_db_list *node)
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
