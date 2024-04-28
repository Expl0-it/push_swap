/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:20:18 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/28 18:47:24 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_db_list	**stack)
{
	if (NULL == *stack || NULL == stack || NULL == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	if (NULL != (*stack)->next)
	{
		(*stack)->prev->next = (*stack)->next;
		(*stack)->next->prev = (*stack)->prev;
	}
	else
		(*stack)->prev->next = NULL;
	(*stack)->prev = (*stack)->next;
	(*stack)->next->prev = (*stack);
	(*stack)->prev = NULL;
}

void	sa(t_db_list **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_printf("sa");
}

void	sb(t_db_list **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_printf("sb");
}

void	ss(t_db_list **a, t_db_list **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_printf("ss");
}
