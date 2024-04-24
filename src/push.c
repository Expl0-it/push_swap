/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:47:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 13:39:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	push(t_db_list **src, t_db_list **dst)
{
	t_db_list	*tmp;

	if (NULL == *src)
		return (1);
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (NULL == dst)
	{
		tmp->next = NULL;
		*dst = tmp;
	}
	else
	{
		tmp->next = *dst;
		tmp->next->prev = tmp;
		*dst = tmp;
	}
	return (0);
}
