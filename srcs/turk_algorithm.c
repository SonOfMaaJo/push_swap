/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   turk_algorithm.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 14:46:18 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 04:22:54 by vnaoussi         ###   ########.fr       */
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

static void	sort_less_three(t_pile **pile, char **operations)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*pile)->number;
	n2 = ((*pile)->next)->number;
	if ((*pile)->next == (*pile)->previous)
	{
		if (n1 > n2)
			swap("sa\n", pile, *operations, THRESHOLD);
		return ;
	}
	n3 = ((*pile)->previous)->number;
	if (n1 > n2 && n1 > n3)
		rotate(1, "ra\n", pile, *operations, THRESHOLD);
	else if (n2 > n1 && n2 > n3)
		rev_rotate(1, "rra\n", pile, *operations, THRESHOLD);
	if ((*pile)->number > ((*pile)->next)->number)
		swap("sa\n", pile, *operations, THRESHOLD);
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
		ft_strlcat(*op, ops, THRESHOLD);
		free(ops);
		if (!push("pb\n", pileA, pileB, *op, THRESHOLD))
			return (0);
		if (process_t_algo(ac, len - 1, pileA, pileB, op))
			return (1);
	}
	return (0);
}

static int	final_process(int len, t_pile **pileA, t_pile **pileB, char **op)
{
	int	pos;

	if (*pileB == NULL)
		return (reorder(len, pileA, op), 1);
	pos = get_pos_target_in_a((*pileB)->number, pileA);
	if (pos - 1 <= len / 2)
		rotate(pos - 1, "ra\n", pileA, *op, THRESHOLD);
	else
		rev_rotate(len - pos + 1, "rra\n", pileA, *op, THRESHOLD);
	if (!push("pa\n", pileB, pileA, *op, THRESHOLD))
		return (0);
	return (final_process(len + 1, pileA, pileB, op));
}

int	turk_algorithm(int ac, t_pile **pileA, t_pile **pileB)
{
	char	*operations;
	int		len;

	operations = (char *)malloc(sizeof(char) * THRESHOLD);
	if (!operations)
		return (0);
	operations[0] = '\0';
	len = ac - 1;
	if (ac >= 5)
		len -= push("pb\n", pileA, pileB, operations, THRESHOLD);
	if (ac > 5)
		len -= push("pb\n", pileA, pileB, operations, THRESHOLD);
	if ((ac == 5 && len != ac - 2) || (ac >= 6 && len != ac - 3))
		return (free(operations), 0);
	if (process_t_algo(ac, len, pileA, pileB, &operations))
		if (final_process(3, pileA, pileB, &operations))
			return (ft_printf("%s", operations), free(operations), 1);
	return (free(operations), 0);
}
