/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:21:21 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 03:50:04 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_pile **pile)
{
	t_pile	*node;
	t_pile	*other_node;

	if (pile == NULL)
		return ;
	if (*pile == NULL)
	{
		free(pile);
		return ;
	}
	node = (*pile)->next;
	other_node = NULL;
	while (node != *pile)
	{
		other_node = node->next;
		free(node);
		node = other_node;
	}
	free(node);
	free(pile);
	pile = NULL;
}

void	print_pile(t_pile **pile)
{
	t_pile	*node;

	if (!pile || *pile == NULL)
		return ;
	ft_printf("%d : %d (%p   %p)\n", (*pile)->pos, (*pile)->number, *pile, (*pile)->previous);
	node = (*pile)->next;
	while (node != *pile)
	{
		ft_printf("%d : %d (%p  %p)\n", node->pos, node->number, node, (node)->previous);
		node = node->next;
	}
}

static int	is_valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	while (i < ac)
	{
		j = 0;
		if (av[i][j] == '-' && av[i][j + 1])
			j++;
		while (av[i][j])
		{
			if (ft_strchr("0123456789", av[i][j]) == NULL)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int set_pile(t_pile **head, int ac, char **av)
{
	t_pile	*node;
	int		i;

	i = 1;
	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (0);
	*head = node;
	while (i < ac)
	{
		node->pos = i;
		node->number = ft_atoi(av[i]);
		if (i++ != ac - 1)
		{
			node->next = (t_pile *)malloc(sizeof(t_pile));
			if (!(node->next))
				return (free_pile(head), 0);
			(node->next)->previous = node;
			node = node->next;
		}
	}
	(*head)->previous = node;
	node->next = *head;
	return (1);
}

int	main(int ac, char **av)
{
	t_pile	**pileA;
	t_pile	**pileB;

	pileA = (t_pile **)malloc(sizeof(t_pile *));
	if ((ac <= 1 || !is_valid(ac, av)) && pileA)
		return (ft_printf("Error\n"), free(pileA), 1);
	pileB = (t_pile **)malloc(sizeof(t_pile *));
	if (!pileB)
		return (ft_printf("Error\n"), free(pileA), 1);
	if (!set_pile(pileA, ac, av))
		return(ft_printf("Error\n"), free(pileB), free(pileA), 1);
	*pileB = NULL;
	if (!check_sort(pileA))
		turk_algorithm(ac, pileA, pileB);
	print_pile(pileA);
	ft_printf("-------------------------------------------\n\n");
	print_pile(pileB);
	free_pile(pileA);
	free_pile(pileB);
	return (EXIT_SUCCESS);
}
