/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:50:14 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/20 12:23:41 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static void	remove_head(t_pile **pile)
{
	t_pile	*node;

	((*pile)->next)->previous = (*pile)->previous;
	((*pile)->previous)->next = (*pile)->next;
	node = *pile;
	if ((*pile)->next == *pile)
	{
		free(*pile);
		*pile = NULL;
		return ;
	}
	*pile = (*pile)->next;
	free(node);
}

void	swap(t_pile **pile)
{
	int		num_temp;

	if (pile == NULL || *pile == NULL || (*pile)->next == *pile)
		return ;
	if ((*pile)->next == *pile)
		return ;
	num_temp = (*pile)->number;
	(*pile)->number = ((*pile)->next)->number;
	((*pile)->next)->number = num_temp;
}

int	push(t_pile **pileA, t_pile **pileB)
{
	t_pile	*node;

	if (!pileA || *pileA == NULL)
		return (1);
	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (0);
	node->number = (*pileA)->number;
	node->next = node;
	node->previous = node;
	remove_head(pileA);
	if (*pileB)
	{
		node->next = *pileB;
		node->previous = (*pileB)->previous;
		(*pileB)->previous = node;
		((node)->previous)->next = node;
	}
	*pileB = node;
	return (1);
}

void	rotate(t_pile **pile)
{
	if (pile == NULL || *pile == NULL)
		return ;
	*pile = (*pile)->next;
}

void	rev_rotate(t_pile **pile)
{
	if (pile == NULL || *pile == NULL)
		return ;
	*pile = (*pile)->previous;
}
