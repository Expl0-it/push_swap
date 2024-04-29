/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:20:18 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/29 13:43:38 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap(t_db_list	**stack)
{
	if (NULL == *stack || NULL == stack || NULL == (*stack)->next)
		return ;
	*stack = (*stack)->next;
	(*stack)->prev->prev = *stack;
	(*stack)->prev->next = (*stack)->next;
	if (NULL != (*stack)->next)
		(*stack)->next->prev = (*stack)->prev;
	(*stack)->next = (*stack)->prev;
	(*stack)->prev = NULL;
}

void	sa(t_db_list **a, bool checker)
{
	swap(a);
	if (!checker)
		ft_printf("sa\n");
}

void	sb(t_db_list **b, bool checker)
{
	swap(b);
	if (!checker)
		ft_printf("sb\n");
}

void	ss(t_db_list **a, t_db_list **b, bool checker)
{
	swap(a);
	swap(b);
	if (!checker)
		ft_printf("ss\n");
}
