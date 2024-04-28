/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:47:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/28 18:47:27 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_db_list **src, t_db_list **dst)
{
	t_db_list	*tmp;

	if (NULL == *src)
		return ;
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
}

void	pa(t_db_list **a, t_db_list **b, bool checker)
{
	push(a, b);
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_db_list **b, t_db_list **a, bool checker)
{
	push(b, a);
	if (!checker)
		ft_printf("pb\n");
}
