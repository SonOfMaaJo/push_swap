/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_valids.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 18:34:13 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 16:53:47 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_len(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return (0);
	while (args[i])
		i++;
	return (i);
}

static int	is_valid_int(char **av)
{
	int	i;
	int	j;

	i = -1;
	if (av == NULL)
		return (0);
	while (av[++i])
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (ft_strchr("0123456789", av[i][j]) == NULL)
				return (0);
			j++;
		}
	}
	return (1);
}

static	int	is_doublon_int(char **av)
{
	int	i;
	int	j;

	i = 0;
	if (av == NULL)
		return (0);
	while (av[i])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_strcmp(av[i], av[j]) == 0)
				return (0);
			j++;
		}
		i++;
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
	i = 1;
	arg = NULL;
	if (args)
	{
		while (i < ac)
		{
			arg = ft_strdup(av[i]);
			if (!arg)
				return (free_args(args), NULL);
			args[i - 1] = arg;
			i++;
		}
		args[ac - 1] = NULL;
	}
	return (args);
}

int	*trans_to_p_int(int ac, char **av, int *size)
{
	int		*numbers;
	int		i;
	long	number;
	char	**args;

	args = seg_numbers(ac, av);
	if (!args)
		return (NULL);
	*size = ft_len(args);
	if (!is_valid_int(args) || !is_doublon_int(args))
		return (free_args(args), NULL);
	numbers = (int *)malloc(sizeof(int) * (*size));
	i = 0;
	if (numbers)
	{
		while (i++ < *size)
		{
			number = ps_atoi(args[i - 1]);
			if (number < (long)INT_MIN || number > (long)INT_MAX)
				return (free_args(args), free(numbers), NULL);
			numbers[i - 1] = (int)number;
		}
	}
	return (free_args(args), numbers);
}
