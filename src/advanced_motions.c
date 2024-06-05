/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   advanced_motions.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/19 15:52:57 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/05 14:39:16 by mamichal         ###   ########.fr       */
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

void	rotate_both(t_stack *a, t_stack *b, t_db_list *cheapest)
{
	while (a->node != cheapest->utils.target && b->node != cheapest)
		rr(a, b, false);
	set_position(*a);
	set_position(*b);
}

void	reverse_rotate_both(t_stack *a, t_stack *b, t_db_list *cheapest)
{
	while (a->node != cheapest->utils.target && b->node != cheapest)
		rrr(a, b, false);
	set_position(*a);
	set_position(*b);
}

void	move_nodes(t_stack *a, t_stack *b)
{
	t_db_list	*cheapest;

	cheapest = return_cheapest(*b);
	if (cheapest->utils.above_median && \
		cheapest->utils.target->utils.above_median)
		rotate_both(a, b, cheapest);
	else if (!(cheapest->utils.above_median) && \
			!(cheapest->utils.target->utils.above_median))
		reverse_rotate_both(a, b, cheapest);
	put_node_on_top(b, cheapest, 'b');
	put_node_on_top(a, cheapest->utils.target, 'a');
	pa(a, b, false);
}
