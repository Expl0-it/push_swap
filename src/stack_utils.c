/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 11:24:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/05 21:29:52 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

bool	is_sorted(t_db_list *node)
{
	if (NULL == node)
		return (true);
	while (node->next)
	{
		if (node->value > node->next->value)
			return (false);
		node = node->next;
	}
	return (true);
}
