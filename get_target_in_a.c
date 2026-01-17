/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target_in_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/17 01:17:34 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 04:06:06 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_pile	**get_min_max(t_pile **pile)
{
	t_pile	*node;
	t_pile	**min_max;

	min_max = (t_pile **)malloc(sizeof(t_pile *) * 2);
	if (!min_max)
		return (NULL);
	min_max[0] = *pile;
	min_max[1] = *pile;
	node = (*pile)->next;
	while (node != *pile)
	{
		if (node->number > (min_max[1])->number)
			min_max[1] = node;
		if (node->number < (min_max[0])->number)
			min_max[0] = node;
		node = node->next;
	}
	return (min_max);
}

void	reorder(int len, t_pile **pile, char **operations)
{
	t_pile	*min;
	t_pile	*node;

	min = *pile;
	node = (*pile)->next;
	while (node != *pile)
	{
		if (node->number < min->number)
			min = node;
		node = node->next;
	}
	if (min->pos - 1 <= len / 2)
		rotate(min->pos - 1, "ra\n", pile, *operations, THRESHOLD);
	else
		rev_rotate(len - min->pos + 1, "rra\n", pile, *operations, THRESHOLD);
}

int	get_pos_target_in_a(int number, t_pile **pileA)
{
	t_pile	*node;
	t_pile	**min_max;
	int		pos;

	min_max = get_min_max(pileA);
	pos = 0;
	if (!min_max)
		return (0);
	if (number >= (min_max[1])->number || number <= (min_max[0])->number)
	{
		pos = min_max[0]->pos;
		return (free(min_max), pos);
	}
	node = min_max[0];
	while (node->number < number)
		node = node->next;
	return (free(min_max), node->pos);
}
