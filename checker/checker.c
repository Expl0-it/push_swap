/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 14:01:24 by mamichal          #+#    #+#             */
/*   Updated: 2024/06/03 15:36:05 by mamichal         ###   ########.fr       */
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

static void	exec_command(t_stack *a, t_stack *b, char *command)
{
	if (!ft_strncmp(command, "pa\n", 3))
		pa(a, b, true);
	else if (!ft_strncmp(command, "pb\n", 3))
		pb(b, a, true);
	else if (!ft_strncmp(command, "sa\n", 3))
		sa(a, true);
	else if (!ft_strncmp(command, "sb\n", 3))
		sb(b, true);
	else if (!ft_strncmp(command, "ss\n", 3))
		ss(a, b, true);
	else if (!ft_strncmp(command, "ra\n", 3))
		ra(a, true);
	else if (!ft_strncmp(command, "rb\n", 3))
		rb(b, true);
	else if (!ft_strncmp(command, "rr\n", 3))
		rr(a, b, true);
	else if (!ft_strncmp(command, "rra\n", 4))
		rra(a, true);
	else if (!ft_strncmp(command, "rrb\n", 4))
		rrb(b, true);
	else if (!ft_strncmp(command, "rrr\n", 4))
		rrr(a, b, true);
	else
		handle_error(a, b);
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
		exec_command(&a, &b, next_line);
		next_line = get_next_line(STDIN_FILENO);
	}
	if (stack_is_sorted(a.node) && b.size == 0)
		write(STDOUT_FILENO, "OK\n", 3);
	else
		write(STDOUT_FILENO, "KO\n", 3);
	free_stacks(&a, &b);
	return (OK);
}
