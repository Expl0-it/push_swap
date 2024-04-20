/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:22:52 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/20 22:28:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_stack_node	*db_lstnew(int value)
{
	t_stack_node	*new;

	new = (t_stack_node *)malloc(sizeof(t_list));
	if (NULL == new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}
