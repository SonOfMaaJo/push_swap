/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:50:14 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/05 19:18:34 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_pile **pile)
{
	int	num_temp;

	if	(pile == NULL || *pile == NULL || (*pile)->next == *pile)
		return ;
	num_temp = (*pile)->number;
	(*pile)->number = ((*pile)->next)->number;
	((*pile)->next)->number = num_temp;
}

void	push(t_pile **pileA, t_pile **pileB)
{
	t_pile	*node;

	if (*pileB == NULL)
		return ;
	node = *pileA;
	((*pileB)->previous)->next = node;
	(*pileB)->previous = node;
	(node->next)->previous = node->previous;
	(node->previous)->next = node->next;
	*pileA = node->next;
	node->next = *pileB;
	node->previous = (*pileB)->previous;
	*pileB = node;
}

void	rotate(t_pile **pile)
{
	if (*pile == NULL)
		return ;
	*pile = (*pile)->next;
}

void	rev_rotate(t_pile **pile)
{
	if (*pile == NULL)
		return ;
	*pile = (*pile)->previous;
}
