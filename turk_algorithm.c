/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:46:18 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/08 03:21:59 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_sort(t_pile **pile)
{
	t_pile	*node;

	if (!pile || !*pile)
		return (1);
	node = *pile;

	while (node->next != *pile)
	{
		if ((node->next)->number < node->number)
			return (0);
		node = node->next;
	}
	return (1);
}

int	sort_less_three(t_pile **pile, char **operations)
{
	if (((*pile)->next)->number < (*pile)->number)
	{
		ft_strlcat(*operations, "sa\n", 30000);
		swap(pile);
		return (1);
	}
	if (((*pile)->previous)->number < (*pile)->number)
	{
		ft_strlcat(*operations, "rra\n", 30000);
		rev_rotate(pile);
		return (1);
	}
	if (((*pile)->previous)->number < ((*pile)->next)->number)
	{
		ft_strlcat(*operations, "rra\n", 30000);
		rev_rotate(pile);
		ft_strlcat(*operations, "sa\n", 30000);
		swap(pile);
	}
	return (1);
}

int	process_t_algo(int ac, int len, t_pile **pileA, t_pile **pileB, char **op)
{
	int		*cost;
	char	*ops;

	if (len <= 3)
		return (sort_less_three(pileA, op), 1);
	else
	{
		cost = get_cost(ac, len, pileA, pileB);
		if (!cost)
			return (0);
		ops = mov(ac, len, cost, pileA, pileB);
		free(cost);
		if (!ops)
			return (0);
		ft_strlcat(*op, ops, 30000);
		free(ops);
		if (!push(pileA, pileB))
			return (0);
		ft_strlcat(*op, "pb\n", 30000);
		if (process_t_algo(ac, len - 1, pileA, pileB, op))
			return (1);
	}
	return (0);
}

int	turk_algorithm(int ac, t_pile **pileA, t_pile **pileB)
{
	int		len;
	char	*operations;

	operations = (char *)malloc(sizeof(char) * 30000);
	if (!operations)
		return (0);
	operations[0] = '\0';

	len = ac - 1;
	if (len == 4)
	{
		if (!push(pileA, pileB))
			return (free(operations), 0);
		ft_strlcat(operations, "pb\n", 30000);
		len--;
	}
	else if (ac - 1 > 4)
	{
		if (!push(pileA, pileB) || !push(pileA, pileB))
			return (free(operations), 0);
		ft_strlcat(operations, "pb\npb\n", 30000);
		len = len - 2;
	}
	if (process_t_algo(ac, len, pileA, pileB, &operations))
		return (ft_printf("%s", operations), free(operations), 1);
	free(operations);
	return (0);
}
