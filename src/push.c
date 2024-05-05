/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 10:47:56 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/05 13:58:23 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	push(t_db_list **dst, t_db_list **src, int *size_dst, int *size_src)
{
	t_db_list	*tmp;

	if (NULL == *src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (*src)
		(*src)->prev = NULL;
	tmp->prev = NULL;
	if (NULL == *dst)
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
	*size_src = *size_src - 1;
	*size_dst = *size_dst + 1;
}

void	pa(t_db_list **a, t_db_list **b, t_stack_sizes **sizes, bool checker)
{
	push(a, b, (&(*sizes)->size_a), (&(*sizes)->size_b));
	if (!checker)
		ft_printf("pa\n");
}

void	pb(t_db_list **b, t_db_list **a, t_stack_sizes **sizes, bool checker)
{
	push(b, a, (&(*sizes)->size_b), (&(*sizes)->size_a));
	if (!checker)
		ft_printf("pb\n");
}
