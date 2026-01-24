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

static void	sort_less_three(t_pile **pile, t_ops *ops)
{
	int	n1;
	int	n2;
	int	n3;

	n1 = (*pile)->number;
	n2 = ((*pile)->next)->number;
	if ((*pile)->next == (*pile)->previous)
	{
		if (n1 > n2)
			swap("sa\n", pile, ops);
		return ;
	}
	n3 = ((*pile)->previous)->number;
	if (n1 > n2 && n1 > n3)
		rotate(1, "ra\n", pile, ops);
	else if (n2 > n1 && n2 > n3)
		rev_rotate(1, "rra\n", pile, ops);
	if ((*pile)->number > ((*pile)->next)->number)
		swap("sa\n", pile, ops);
}

int	process_t_algo(int info[2], t_pile **pileA, t_pile **pileB, t_ops *ops)
{
	int		*cost;
	char	*moves;
	int		next_info[2];

	if (info[1] <= 3)
		return (sort_less_three(pileA, ops), 1);
	cost = get_cost(info[0], info[1], pileA, pileB);
	if (!cost)
		return (0);
	moves = mov(info, cost, pileA, pileB);
	free(cost);
	if (!moves)
		return (0);
	ft_strlcat(ops->s, moves, ops->size);
	free(moves);
	if (!push("pb\n", pileA, pileB, ops))
		return (0);
	next_info[0] = info[0];
	next_info[1] = info[1] - 1;
	if (process_t_algo(next_info, pileA, pileB, ops))
		return (1);
	return (0);
}

static int	final_process(int len, t_pile **pileA, t_pile **pileB, t_ops *ops)
{
	int	pos;

	if (*pileB == NULL)
		return (reorder(len, pileA, ops), 1);
	pos = get_pos_target_in_a((*pileB)->number, pileA);
	if (pos - 1 <= len / 2)
		rotate(pos - 1, "ra\n", pileA, ops);
	else
		rev_rotate(len - pos + 1, "rra\n", pileA, ops);
	if (!push("pa\n", pileB, pileA, ops))
		return (0);
	return (final_process(len + 1, pileA, pileB, ops));
}

int	turk_algorithm(int ac, t_pile **pileA, t_pile **pileB)
{
	t_ops	ops;
	int		len;
	int		info[2];

	ops.size = THRESHOLD;
	ops.s = (char *)malloc(sizeof(char) * ops.size);
	if (!ops.s)
		return (0);
	ops.s[0] = '\0';
	len = ac - 1;
	if (ac >= 5)
		len -= push("pb\n", pileA, pileB, &ops);
	if (ac > 5)
		len -= push("pb\n", pileA, pileB, &ops);
	if ((ac == 5 && len != ac - 2) || (ac >= 6 && len != ac - 3))
		return (free(ops.s), 0);
	info[0] = ac;
	info[1] = len;
	if (process_t_algo(info, pileA, pileB, &ops))
		if (final_process(3, pileA, pileB, &ops))
			return (ft_printf("%s", ops.s), free(ops.s), 1);
	return (free(ops.s), 0);
}
