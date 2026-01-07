/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 00:05:46 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/07 02:45:28 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	get_target_pos(int number, int len, t_pile **pileB)
{
	t_pile	*target;


	target = NULL;
	if (number >= (*pileB)->number || number <= ((*pileB)->previous)->number)
		return (0);
	target = *pileB;
	while (target->number > number)
		target = target->next;
	if (target->pos > len / 2)
		return (len - target->pos + 1);
	else
		return (target->pos - 1);
}

static void get_el(int ac, int *cost, int len, t_pile **pileA, t_pile **pileB)
{
	t_pile		*node;
	int			costA;
	int			costB;

	node = *pileA;
	costA = -1;
	while (node != *pileA || costA == -1)
	{
		if (node->pos <= len / 2)
			costA = node->pos - 1;
		else
			costA = len - node->pos + 1;
		costB = get_target_pos(node->number, ac - len, pileB);
		if (costA + costB < cost[0] + cost[1])
		{
			cost[0] = costA;
			cost[1] = costB;
		}
		node = node->next;
	}
}

static void	mov(int ac, int len, int *cost,  t_pile **pileA, t_pile **pileB)
{
	if (cost[0] + 1 <= len / 2 && cost[1] + 1 <= (ac - len) / 2)
		rotate_up(cost[0], cost[1], pileA, pileB);
	if (cost[0] + 1 > len / 2 && cost[1] + 1 > (ac - len) / 2)
		rotate_down(cost[0], cost[1], pileA, pileB);
	if (cost[0] + 1 <= len / 2 && cost[1] + 1 > (ac - len) / 2)
		rotate_upA_DB(cost[0], cost[1], pileA, pileB);
	if (cost[0] + 1 > len / 2 && cost[1] + 1 <= (ac - len) / 2)
		rotate_DA_upB(cost[0], cost[1], pileA, pileB);
}

