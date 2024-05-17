/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:31:49 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/16 13:45:24 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

void	set_position(t_stack *stack)
{
	int	i;
	int	mid_size;

	i = 0;
	if (NULL == stack)
		return;
	mid_size = stack->size / 2;
	while (stack->node)
	{
		stack->node->utils.curr_pos = i;
		if (i <= mid_size)
			stack->node->utils.above_median = true;
		else
			stack->node->utils.above_median = false;
		stack->node = stack->node->next;
		i++;
	}
}

void	set_target(t_stack *a, t_stack *b)
{
	t_db_list	*current_a;
	t_db_list	*target;
	long		best_match;

	while (b->node)
	{
		best_match = LONG_MAX;
		current_a = a->node;
		while (current_a)
		{
			if (current_a->value > b->node->value
				&& current_a->value < best_match)
			{
				best_match = current_a->value;
				target = current_a;
			}
			current_a = current_a->next;
		}
		if (LONG_MAX == best_match)
			b->node->utils.target = find_smallest(a->node);
		else
			b->node->utils.target = target;
		b->node = b->node->next;
	}
}

void	init_list_utils(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
	set_target(a, b);
}
