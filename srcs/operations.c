/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 17:50:14 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 03:36:47 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	update_pos(t_pile **pile, int remove)
{
	int		i;
	t_pile	*node;

	if (remove)
	{
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
	i = 1;
	(*pile)->pos = i++;
	node = (*pile)->next;
	while (node != *pile)
	{
		node->pos = i++;
		node = node->next;
	}
}

void	swap(char *name, t_pile **pile, t_ops *ops)
{
	int		num_temp;

	if (pile == NULL || *pile == NULL || (*pile)->next == *pile)
		return ;
	if ((*pile)->next == *pile)
		return ;
	num_temp = (*pile)->number;
	(*pile)->number = ((*pile)->next)->number;
	((*pile)->next)->number = num_temp;
	if (ops && ops->s)
		ft_strlcat(ops->s, name, ops->size);
}

int	push(char *name, t_pile **pileA, t_pile **pileB, t_ops *ops)
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
	update_pos(pileA, 1);
	if (*pileB)
	{
		node->next = *pileB;
		node->previous = (*pileB)->previous;
		(*pileB)->previous = node;
		((node)->previous)->next = node;
	}
	*pileB = node;
	if (ops && ops->s)
		ft_strlcat(ops->s, name, ops->size);
	return (update_pos(pileB, 0), 1);
}

void	rotate(int cost, char *name, t_pile **pile, t_ops *ops)
{
	int		i;

	i = 0;
	if (pile == NULL || *pile == NULL)
		return ;
	while (i++ < cost)
	{
		*pile = (*pile)->next;
		if (ops && ops->s)
			ft_strlcat(ops->s, name, ops->size);
	}
	if (cost)
		update_pos(pile, 0);
}

void	rev_rotate(int cost, char *name, t_pile **pile, t_ops *ops)
{
	int		i;

	i = 0;
	if (pile == NULL || *pile == NULL)
		return ;
	while (i++ < cost)
	{
		*pile = (*pile)->previous;
		if (ops && ops->s)
			ft_strlcat(ops->s, name, ops->size);
	}
	if (cost)
		update_pos(pile, 0);
}
