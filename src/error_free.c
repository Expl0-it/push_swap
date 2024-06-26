/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:32:09 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/01 14:06:26 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <unistd.h>

bool	error_syntax(char *str_nb)
{
	if (!(*str_nb == '+'
			|| *str_nb == '-'
			|| (ft_isdigit(*str_nb))))
		return (true);
	if (('+' == *str_nb || '-' == *str_nb)
		&& !(ft_isdigit(str_nb[1])))
		return (true);
	while (*++str_nb)
	{
		if (!(ft_isdigit(*str_nb)))
			return (true);
	}
	return (false);
}

bool	error_repetition(t_db_list *a, int nbr)
{
	if (NULL == a)
		return (false);
	while (NULL != a)
	{
		if (a->value == nbr)
			return (true);
		a = a->next;
	}
	return (false);
}

void	free_stack_nodes(t_db_list **first_node)
{
	t_db_list	*tmp;
	t_db_list	*current;

	if (NULL == first_node)
		return ;
	current = *first_node;
	while (current)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	current = NULL;
}

void	free_split(char **argv)
{
	int	i;

	i = 0;
	if (NULL == argv || NULL == *argv)
		return ;
	while (argv[i])
	{
		free(argv[i]);
		i++;
	}
	free(argv);
}

void	error_free(t_db_list **a, char **argv, bool is_argc_2, t_errors code)
{
	if (NULL != a)
		free_stack_nodes(a);
	if (is_argc_2)
		free_split(argv);
	write(2, "Error\n", 6);
	exit(code);
}
