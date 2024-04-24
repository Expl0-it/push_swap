/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:47:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/24 12:16:07 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	pa(t_db_list *a, t_db_list *b)
{
	t_db_list	*tmp;

	if (NULL == b)
		return (1);
	tmp = b;
	b = b->next;
	if (NULL == a)
	{
		a = tmp;
		a->next = NULL;
	}
	else
	{
		a->prev = tmp;
		tmp->next = a;
		a = tmp;
	}
	return (0);
}
