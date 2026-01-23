/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valids.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:34:13 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 17:08:01 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	ft_len_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
		i++;
	return (i);
}

static int	is_valid_ints(char **av)
{
	int	i;
	int	j;
	int	len;

	i = -1;
	if (av == NULL || *av == NULL)
		return (0);
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		len = ft_strlen(&av[i][j]);
		if (len > 10 || len == 0
			|| (len == 10
				&& ft_strncmp(&av[i][j], "2147483647", 10) > 0
			&& ft_strncmp(&av[i][j], "2147483648", 10) != 0))
			return (0);
		while (av[i][j++])
			if (!ft_isdigit(av[i][j - 1]))
				return (0);
	}
	return (1);
}

static	int	is_doublon_ints(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (av == NULL || *av == NULL)
		return (0);
	while (av[i++])
	{
		j = i;
		while (av[j++])
			if (ft_strcmp(av[i - 1], av[j - 1]) == 0)
				return (0);
	}
	return (1);
}

static char	**seg_numbers(int ac, char **av)
{
	char	**args;
	char	*arg;
	int		i;

	if (ac == 2)
		return (ft_split(av[1], ' '));
	args = (char **)malloc(sizeof(char *) * (ac));
	i = 0;
	arg = NULL;
	if (args)
	{
		while (++i < ac)
		{
			arg = ft_strdup(av[i]);
			if (!arg)
				return (free_args(args), NULL);
			args[i - 1] = arg;
		}
		args[ac - 1] = NULL;
	}
	return (args);
}

int	trans_args_to_pints(int ac, char **av, int **numbers)
{
	int		i;
	char	**args;

	args = seg_numbers(ac, av);
	if (!args)
		return (0);
	if (!is_valid_ints(args) || !is_doublon_ints(args))
		return (free_args(args), 0);
	i = ft_len_args(args);
	*numbers = (int *)malloc(sizeof(int) * (i + 1));
	i = 0;
	if (!*numbers)
		return (0);
	while (args[i++])
		(*numbers)[i - 1] = ft_atoi(args[i - 1]);
	return (free_args(args), i - 1);
}
