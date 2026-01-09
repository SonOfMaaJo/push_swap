/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:50:14 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/07 17:53:00 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	*update_r_pos(t_pile **pile, int remove)
{
	int		i;
	t_pile	*node;

	if (remove)
	{
		((*pile)->next)->previous = (*pile)->previous;
		((*pile)->previous)->next = (*pile)->next;
		node = *pile;
		if ((*pile)->next == *pile)
			return(free_pile(pile), NULL);
		*pile = (*pile)->next;
		free(node);
	}
	i = 1;
	(*pile)->pos = i++;
	node = (*pile)->next;
	while (node != *pile)
	{
		node->pos = i++;
		node = node->next;
	}
	return (NULL);
}

void	swap(t_pile **pile)
{
	int	num_temp;

	if	(pile == NULL || *pile == NULL || (*pile)->next == *pile)
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
		return  (0);
	node->number = (*pileA)->number;
	node->next = node;
	node->previous = node;
	update_r_pos(pileA, 1);
	if (*pileB)
	{
		node->next = *pileB;
		node->previous = (*pileB)->previous;
		(*pileB)->previous = node;
		((node)->previous)->next = node;
	}
	*pileB = node;
	return (update_r_pos(pileB, 0), 1);
}

void	rotate(t_pile **pile)
{
	if (pile == NULL || *pile == NULL)
		return ;
	*pile = (*pile)->next;
	update_r_pos(pile, 0);
}

void	rev_rotate(t_pile **pile)
{
	if (pile == NULL || *pile == NULL)
		return ;
	*pile = (*pile)->previous;
	update_r_pos(pile, 0);
}
