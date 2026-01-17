/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valids.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:34:13 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 20:45:34 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = 0;
		if (av[i][j] == '"' && av[i][j+1])
			j++;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		while (av[i][j++])
		{
			if (i == ac - 1 && av[i][j - 1] == '"' && av[i][j])
				return (0);
			if (ft_strchr("0123456789", av[i][j - 1]) == NULL)
				return (0);
		}
	}
	return (1);
}

static	int	is_doublon_int(int ac, char **av)
{
	int	i;
	int	j;

	i = 0;
	while (++i < ac)
	{
		j = i;
		while (++j < ac)
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
	}
	return (1);
}

int	*trans_to_p_int(int ac, char **av)
{
	int		*numbers;
	int		i;
	long	number;

	if (!is_valid_int(ac, av) || !is_doublon_int(ac, av))
		return (NULL);
	numbers = (int *)malloc(sizeof(int) * (ac - 1));
	i = 0;
	if (numbers)
	{
		while (++i < ac)
		{
			number = ft_atoi(av[i]);
			if (number < (long)INT_MIN || number > (long)INT_MAX)
				return (free(numbers), NULL);
			numbers[i - 1] = (int)number;
		}
	}
	return (numbers);
}				
