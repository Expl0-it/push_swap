/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:50:45 by mamichal          #+#    #+#             */
/*   Updated: 2024/05/05 13:39:47 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_db_list	*a;
	t_db_list	*b;
	t_stack_sizes	*sizes;

	a = NULL;
	b = NULL;
	if (argc < 2 || !argv[1][0])
		return (NOT_ENOUGH_ARGUMENTS);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, 2 == argc);

	free_stack(&a);
	return (OK);
}
