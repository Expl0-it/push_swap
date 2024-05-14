/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_node_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/14 12:31:49 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/14 13:17:47 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	set_position(t_stack *stack)
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

void	init_list_utils(t_stack *a, t_stack *b)
{
	set_position(a);
	set_position(b);
}
