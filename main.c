/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:21:21 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/05 19:47:01 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_pile(t_pile **pile)
{
	t_pile	*node;
	t_pile	*other_node;

	node = (*pile)->next;
	other_node = NULL;
	while (node != *pile)
	{
		other_node = node->next;
		free(node);
		node = other_node;
	}
	free(node);
}

void	print_pile(t_pile **pile)
{
	t_pile	*node;
	int		i;

	i = 0;
	ft_printf("%d : %d\n", (*pile)->pos, (*pile)->number);
	node = (*pile)->next;
	while (node != *pile)
	{
		ft_printf("%d : %d\n", node->pos, node->number);
		node = node->next;
	}
} 

static int	is_valid(int ac, char **av)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (i++ < ac)
	{
		j = 0;
		while (av[i - 1][j])
			if (ft_strchr("0123456789", av[i - 1][j++]) == NULL)
				return (0);
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

	pileA = (t_pile **)malloc(sizeof(t_pile *));
	if ((ac <= 1 || !is_valid(ac, av)) && pileA)
	{
		ft_printf("Error : %d\n", ac);
		exit(EXIT_FAILURE);
	}
	if (!set_pile(pileA, ac, av))
		exit(EXIT_FAILURE);
	print_pile(pileA);
	swap(pileA);
	print_pile(pileA);
	free_pile(pileA);
	return (EXIT_SUCCESS);
}
