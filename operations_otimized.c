/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_otimized.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:24:07 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/16 15:26:45 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_up(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int	min;
	int	size;
	char	*operations;

	size = (costA + costB) * 4 + 10;
	operations = (char *)malloc(sizeof(char) * size);
	if (!operations)
		return (NULL);
	operations[0] = '\0';
	if (costA < costB)
		min = costA;
	else
		min = costB;
	rotate(min, "rr\n", pileA, operations, size);
	rotate(min, "rb\n", pileB, NULL, size);
	rotate(costA - min, "ra\n", pileA, operations, size);
	rotate(costB - min, "rb\n", pileB, operations, size);
	return (operations);
}

char	*rotate_down(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int	min;
	int	size;
	char	*operations;

	size = (costA + costB) * 4 + 10;
	operations = (char *)malloc(sizeof(char) * size);
	if (!operations)
		return (NULL);
	operations[0] = '\0';
	if (costA < costB)
		min = costA;
	else
		min = costB;
	rev_rotate(min, "rrr\n", pileA, operations, size);
	rev_rotate(min, "rrb\n", pileB, NULL, size);
	rev_rotate(costA - min, "rra\n", pileA, operations, size);
	rev_rotate(costB - min, "rrb\n", pileB, operations, size);
	return (operations);
}

char	*rotate_upA_DB(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int	size;
	char	*operations;

	size = (costA + costB) * 4 + 10;
	operations = (char *)malloc(sizeof(char) * size);
	if (!operations)
		return (NULL);
	operations[0] = '\0';
	rotate(costA, "ra\n", pileA, operations, size);
	rev_rotate(costB, "rrb\n", pileB, operations, size);
	return (operations);
}

char	*rotate_DA_upB(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int	size;
	char	*operations;

	size = (costA + costB) * 4 + 10;
	operations = (char *)malloc(sizeof(char) * size);
	if (!operations)
		return (NULL);
	operations[0] = '\0';
	rev_rotate(costA, "rra\n", pileA, operations, size);
	rotate(costB, "rb\n", pileB, operations, size);
	return (operations);
}

int	ccost(int len, int lenB,  int pos, int pos_target)
{
	if (pos - 1 <= len / 2 && pos_target - 1 <= lenB / 2)
	{
		if (pos < pos_target)
			return (pos_target - 1);
		else
			return (pos - 1);
	}
	else if (pos - 1 > len / 2 && pos_target - 1 > lenB / 2)
	{
		if (len - pos + 1 > lenB - pos_target - 1)
			return (len - pos + 1);
		else
			return (lenB - pos_target + 1);
	}
	else if (pos - 1 > len / 2 && pos_target <= lenB / 2)
		return (len - pos + pos_target);
	else
		return (lenB - pos_target + pos);
}