/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:37:25 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/20 22:22:19 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"
#include <limits.h>

/** @brief Convert a string to an integer.
 *
 *  The atoi() function converts the initial portion of the string
 *  pointed to by nptr to int.
 *
 *  @param nptr pointer to a string to be converted.
 *  @return Int converted from a string.
 *	@bug overflow not taken care of
 */
long	ft_atol(const char *nptr)
{
	int		minus;
	long	num;

	num = 0;
	minus = 1;
	while (*nptr == ' ' || (*nptr >= 9 && *nptr <= 13))
		nptr++;
	if (*nptr == '+' || *nptr == '-')
	{
		if (*nptr == '-')
			minus *= -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		num = num * 10;
		num += *nptr - 48;
		nptr++;
	}
	return (num * minus);
}

void	stack_init(t_stack_node **a, char **argv, bool is_argc_2)
{
	long	nbr;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (error_syntax(argv[i]))
			error_free(a, argv, is_argc_2, SYNTAX_ERROR);
		nbr = ft_atol(argv[i]);
		if (nbr > INT_MAX || nbr < INT_MIN)
			error_free(a, argv, is_argc_2, INT_OVERFLOW);
		if (error_repetition(*a, nbr))
			error_free(a, argv, is_argc_2, NUMBER_REPETITION);
	}
}
