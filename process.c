/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:05:46 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/08 01:22:32 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_cost(int ac, int len, int pos, int pos_target, int *cost)
{
	int	cost1;
	int	cost2;

	if (cost[0] == len + 1)
		return (1);
	cost1 = ccost(len, ac - len - 1, pos, pos_target);
	cost2 = ccost(len, ac - len - 1, cost[0], cost[1]);
	if (cost1 < cost2)
		return (1);
	return (0);
}

static int	find_target(int number, t_pile **pile)
{
	t_pile	*node;

	node = *pile;
	while (node->number < number)
		node = node->previous;
	return ((node->next)->pos);
}

static int	get_target_pos(int number, int len, t_pile **pileB)
{
	t_pile	*node;
	t_pile	*max;
	t_pile	*min;

	node = *pileB;
	min = *pileB;
	max = *pileB;
	while (node->pos <= len)
	{
		if (node->number > max->number)
			max = node;
		if (node->number < min->number)
			min = node;
		if (node->pos == len)
			break ;
		node = node->next;
	}
	if (number < min->number || number > max->number)
		return (max->pos);
	else
		return (find_target(number, &min));
}

int	*get_cost(int ac, int len, t_pile **pileA, t_pile **pileB)
{
	t_pile	*node;
	int		*cost;
	int		pos_target;

	node = *pileA;
	cost = (int *)malloc(sizeof(int) * 2);
	if (!cost)
		return (NULL);
	cost[0] = len + 1;
	cost[1] = ac - len - 1;
	while (node != *pileA || cost[0] == len + 1)
	{
		pos_target = get_target_pos(node->number, ac - len - 1, pileB);
		if (compare_cost(ac, len, node->pos, pos_target, cost))
		{
			cost[0] = node->pos;
			cost[1] = pos_target;
		}
		node = node->next;
	}
	return (cost);
}

char	*mov(int ac, int len, int *cost, t_pile **pileA, t_pile **pileB)
{
	int	lenb;

	lenb = ac - len - 1;
	if (cost[0] - 1 <= len / 2 && cost[1] - 1 <= lenb / 2)
		return (rotate_up(cost[0] - 1, cost[1] - 1, pileA, pileB));
	if (cost[0] - 1 > len / 2 && cost[1] - 1 > lenb / 2)
		return (rotate_down(len - cost[0] + 1, lenb - cost[1] + 1,
				pileA, pileB));
	if (cost[0] - 1 <= len / 2 && cost[1] - 1 > lenb / 2)
		return (rotate_upA_DB(cost[0] - 1, lenb - cost[1] + 1, pileA, pileB));
	if (cost[0] - 1 > len / 2 && cost[1] - 1 <= lenb / 2)
		return (rotate_DA_upB(len - cost[0] + 1, cost[1] - 1, pileA, pileB));
	return (NULL);
}