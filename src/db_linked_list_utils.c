/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   db_linked_list_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 22:22:52 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/21 17:14:18 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_db_list	*db_lstnew(int value)
{
	t_db_list	*new;

	new = (t_db_list *)malloc(sizeof(t_db_list));
	if (NULL == new)
		return (NULL);
	new->value = value;
	new->prev = NULL;
	new->next = NULL;
	return (new);
}

t_db_list	*db_lstlast(t_db_list *lst)
{
	if (NULL == lst)
		return (NULL);
	while (NULL != lst->next)
	{
		lst = lst->next;
	}
	return (lst);
}

void	db_lstadd_back(t_db_list **lst, t_db_list *element)
{
	t_db_list	*last;
	t_db_list	*previous;

	if (NULL != lst && NULL != element)
	{
		if (NULL != *lst)
		{
			last = db_lstlast(*lst);
			last->next = element;
			element->prev = last;
		}
		else
		{
			*lst = element;
			element->prev = NULL;
		}
	}
}
