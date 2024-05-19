/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 22:50:59 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/19 16:30:11 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static t_db_list	*find_highest(t_stack stack)
{
	int			highest;
	t_db_list	*highest_node;

	if (NULL == stack.node)
		return (NULL);
	highest = INT_MIN;
	while (stack.node)
	{
		if (stack.node->value > highest)
		{
			highest = stack.node->value;
			highest_node = stack.node;
		}
		stack.node = stack.node->next;
	}
	return (highest_node);
}

void	tiny_sort(t_stack *a)
{
	t_db_list	*highest_node;

	highest_node = find_highest(*a);
	if (a->size == 2)
	{
		sa(a, false);
		return ;
	}
	if (a->node == highest_node)
		ra(a, false);
	else if (a->node->next == highest_node)
		rra(a, false);
	if (a->node->value > a->node->next->value)
		sa(a, false);
}

void	a_leave_three(t_stack *a, t_stack *b)
{
	while (a->size > 3)
	{
		init_list_utils(a, b);	
		put_node_on_top(a, find_smallest(a->node), 'a');
		pb(b, a, false);
		ft_printf("%d", a->size);
	}
}
