/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamichal <mamichal@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/20 17:32:09 by mamichal          #+#    #+#             */
/*   Updated: 2024/04/20 18:07:09 by mamichal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

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
	free(argv[i]);
}
