/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:50:59 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/01 14:49:26 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_swap(t_stack *a, t_stack *b)
{
	t_db_list	*smallest;

	if (a->size == 5)
		a_leave_three(a, b);
	else
	{
		while (a->size > 3)
			pb(b, a, false);
	}
	tiny_sort(a);
	while (b->node)
	{
		init_list_utils(*a, *b);
		move_nodes(a, b);
	}
	set_position(*a);
	smallest = find_smallest(a->node);
	if (smallest->utils.above_median)
		while (a->node != smallest)
			ra(a, false);
	else
		while (a->node != smallest)
			rra(a, false);
}
