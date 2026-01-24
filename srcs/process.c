/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:05:46 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 16:51:04 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	compare_cost(int info[4], int *cost)
{
	int	cost1;
	int	cost2;

	if (cost[0] == info[1] + 1)
		return (1);
	cost1 = ccost(info[1], info[0] - info[1] - 1, info[2], info[3]);
	cost2 = ccost(info[1], info[0] - info[1] - 1, cost[0], cost[1]);
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
	int		info[4];

	node = *pileA;
	cost = (int *)malloc(sizeof(int) * 2);
	if (!cost)
		return (NULL);
	cost[0] = len + 1;
	cost[1] = ac - len - 1;
	while (node != *pileA || cost[0] == len + 1)
	{
		info[0] = ac;
		info[1] = len;
		info[2] = node->pos;
		info[3] = get_target_pos(node->number, ac - len - 1, pileB);
		if (compare_cost(info, cost))
		{
			cost[0] = info[2];
			cost[1] = info[3];
		}
		node = node->next;
	}
	return (cost);
}

char	*mov(int info[2], int *cost, t_pile **pileA, t_pile **pileB)
{
	int	lenb;

	lenb = info[0] - info[1] - 1;
	if (cost[0] - 1 <= info[1] / 2 && cost[1] - 1 <= lenb / 2)
		return (rotate_up(cost[0] - 1, cost[1] - 1, pileA, pileB));
	if (cost[0] - 1 > info[1] / 2 && cost[1] - 1 > lenb / 2)
		return (rotate_down(info[1] - cost[0] + 1, lenb - cost[1] + 1,
				pileA, pileB));
	if (cost[0] - 1 <= info[1] / 2 && cost[1] - 1 > lenb / 2)
		return (rotate_upa_db(cost[0] - 1, lenb - cost[1] + 1, pileA, pileB));
	if (cost[0] - 1 > info[1] / 2 && cost[1] - 1 <= lenb / 2)
		return (rotate_da_upb(info[1] - cost[0] + 1,
				cost[1] - 1, pileA, pileB));
	return (NULL);
}
