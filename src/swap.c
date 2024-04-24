/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 23:20:18 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 23:37:48 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	swap(t_db_list	**stack)
{
	if (NULL == *stack || NULL == stack || NULL == (*stack)->next)
		return ;
	*stack = (*stack)->next;
}
