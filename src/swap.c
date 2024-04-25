/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:20:18 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/25 20:40:03 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_db_list	**stack)
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
