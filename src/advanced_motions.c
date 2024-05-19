/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_motions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:52:57 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/19 15:58:34 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	put_node_on_top(t_stack *stack, t_db_list *top_node, char stack_name)
{
	while (stack->node != top_node)
	{
		if ('a' == stack_name)
		{
			if (top_node->utils.above_median)
				ra(stack, false);
			else
				rra(stack, false);
		}
		else if ('b' == stack_name)
		{
			if (top_node->utils.above_median)
				rb(stack, false);
			else
				rrb(stack, false);
		}
	}
}
