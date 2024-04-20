/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:50:45 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/20 17:25:32 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;

	a = NULL;
	b = NULL;

	if (argc < 2 || !argv[1][0])
		return (NOT_ENOUGH_ARGUMENTS);
	else if (2 == argc)
		argv = ft_split(*argv, ' ');
	stack_init(&a, argv, 2 == argc);
}
