/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 19:37:25 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/18 11:26:36 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	int	minus;
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

/*
#include <stdio.h>

int	main(void)
{
	long a = ft_atol("   	-9872147483649");
	printf("%ld", a);
	return (0);
}
*/
