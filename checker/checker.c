/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:01:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/03 15:02:20 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./checker.h"

static void	free_stacks(t_stack *a, t_stack *b)
{
	if (b->size != 0)
		free_stack_nodes(&(b->node));
	free_stack_nodes(&(a->node));
}

static void	handle_error(t_stack *a, t_stack *b)
{
	free_stacks(a, b);
	write(STDERR_FILENO, "Error\n", 6);
	exit(CHECKER_COMMAND_ERROR);
}

int	main(int argc, char **argv)
{
	t_stack	a;
	t_stack	b;
	char	*next_line;

	a.node = NULL;
	b.node = NULL;
	if (argc < 2 || !argv[1][0])
		return (NOT_ENOUGH_ARGUMENTS);
	else if (2 == argc)
		argv = ft_split(argv[1], ' ');
	stack_init(&a, argv, 2 == argc);
	stack_set_sizes(&a, &b);
	next_line = get_next_line(STDIN_FILENO);
	while (next_line)
	{
		exec_command();
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted(a.node) && b.size == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stacks(&a, &b);
	return (OK);
}
