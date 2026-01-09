/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_otimized.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 01:24:07 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/08 02:23:47 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*rotate_up(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int		min;
	int		i;
	int		size;
	char	*op;

	i = 1;
	size = (costA + costB) * 4 + 10;
	op = (char *)malloc(sizeof(char) * size);
	if (!op)
		return (NULL);
	op[0] = '\0';
	if (costA < costB)
		min = costA;
	else
		min = costB;
	while (i++ <= min)
	{
		ft_strlcat(op, "rr\n", size);
		rotate(pileA);
		rotate(pileB);
	}
	i = 1;
	while (i++ <= costA - min)
	{
		ft_strlcat(op, "ra\n", size);
		rotate(pileA);
	}
	i = 1;
	while (i++ <= costB - min)
	{
		ft_strlcat(op, "rb\n", size);
		rotate(pileB);
	}
	return (op);
}

char	*rotate_down(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int		min;
	int		size;
	char	*op;

	size = (costA + costB) * 4 + 10;
	op = (char *)malloc(sizeof(char) * size);
	if (!op)
		return (NULL);
	op[0] = '\0';
	if (costA < costB)
		min = costA;
	else
		min = costB;
	while (min-- > 0)
	{
		ft_strlcat(op, "rrr\n", size);
		rev_rotate(pileA);
		rev_rotate(pileB);
	}
	min = 1;
	while (min++ <= costA - costB)
	{
		ft_strlcat(op, "rra\n", size);
		rev_rotate(pileA);
	}
	min = 1;
	while (min++ <= costB - costA)
	{
		ft_strlcat(op, "rrb\n", size);
		rev_rotate(pileB);
	}
	return (op);
}

char	*rotate_upA_DB(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int		i;
	int		size;
	char	*op;

	i = 1;
	size = (costA + costB) * 4 + 10;
	op = (char *)malloc(sizeof(char) * size);
	if (!op)
		return (NULL);
	op[0] = '\0';
	while (i++ <= costA)
	{
		ft_strlcat(op, "ra\n", size);
		rotate(pileA);
	}
	i = 1;
	while (i++ <= costB)
	{
		ft_strlcat(op, "rrb\n", size);
		rev_rotate(pileB);
	}
	return (op);
}

char	*rotate_DA_upB(int costA, int costB, t_pile **pileA, t_pile **pileB)
{
	int		i;
	int		size;
	char	*op;

	i = 1;
	size = (costA + costB) * 4 + 10;
	op = (char *)malloc(sizeof(char) * size);
	if (!op)
		return (NULL);
	op[0] = '\0';
	while (i++ <= costA)
	{
		ft_strlcat(op, "rra\n", size);
		rev_rotate(pileA);
	}
	i = 1;
	while (i++ <= costB)
	{
		ft_strlcat(op, "rb\n", size);
		rotate(pileB);
	}
	return (op);
}

int	ccost(int len, int lenB,  int pos, int pos_target)
{
	if (pos - 1 <= len / 2 && pos_target - 1 <= lenB / 2)
	{
		if (pos  < pos_target)
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