/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:50:45 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/18 09:54:08 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (NOT_ENOUGH_ARGUMENTS);
	if (2 == argc)
		argv = ft_split(*argv, ' ');
}
