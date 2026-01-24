/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:21:21 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 17:13:19 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

static int	set_pile(t_pile **head, int *nbs, int size)
{
	t_pile	*node;
	int		i;

	i = -1;
	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (free(nbs), 0);
	*head = node;
	while (++i < size)
	{
		node->number = nbs[i];
		if (i != size - 1)
		{
			node->next = (t_pile *)malloc(sizeof(t_pile));
			if (!(node->next))
				return (free(nbs), free_pile(head), 0);
			(node->next)->previous = node;
			node = node->next;
		}
	}
	(*head)->previous = node;
	node->next = *head;
	return (free(nbs), 1);
}

int	check_sort(t_pile **pile)
{
	t_pile	*node;

	if (!pile || !*pile)
		return (1);
	node = *pile;
	while (node->next != *pile)
	{
		if ((node->next)->number < node->number)
			return (0);
		node = node->next;
	}
	return (1);
}

static int	init_checker(t_pile ***piles, int ***nbs, int ac, char **av)
{
	int	size;

	*nbs = (int **)malloc(sizeof(int *));
	piles[0] = (t_pile **)malloc(sizeof(t_pile *));
	if (!piles[0] || !*nbs)
		return (ft_printf("Error\n"), free(piles[0]), free(*nbs), -1);
	size = trans_args_to_pints(ac, av, *nbs);
	if (size == 0)
		return (ft_printf("Error\n"), free(piles[0]), free(*nbs), -1);
	piles[1] = (t_pile **)malloc(sizeof(t_pile *));
	if (!piles[1])
		return (ft_printf("Error\n"), free(**nbs), free(*nbs),
			free(piles[0]), -1);
	if (!set_pile(piles[0], **nbs, size))
		return (ft_printf("Error\n"), free(piles[1]), free(piles[0]), -1);
	*(piles[1]) = NULL;
	return (size);
}

int	main(int ac, char **av)
{
	t_pile	**piles[2];
	int		**nbs;
	int		size;

	if (ac < 2)
		return (EXIT_SUCCESS);
	size = init_checker(piles, &nbs, ac, av);
	if (size == -1)
		return (1);
	if (process_check(piles[0], piles[1]))
	{
		if (check_sort(piles[0]) && !(*(piles[1])))
			ft_printf("OK\n");
		else
			ft_printf("KO\n");
		return (free_pile(piles[0]), free_pile(piles[1]), 0);
	}
	else
	{
		ft_printf("Error\n");
		return (free_pile(piles[0]), free_pile(piles[1]), 1);
	}
}
