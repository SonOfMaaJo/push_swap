/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 18:21:21 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/17 19:30:01 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_pile(t_pile **pile)
{
	t_pile	*node;
	t_pile	*other_node;

	if (pile == NULL)
		return (NULL);
	if (*pile == NULL)
		return (free(pile), NULL);
	node = (*pile)->next;
	other_node = NULL;
	while (node != *pile)
	{
		other_node = node->next;
		free(node);
		node = other_node;
	}
	return (free(node), free(pile), NULL);
}

static int set_pile(t_pile **head, int ac, int *numbers)
{
	t_pile	*node;
	int		i;

	i = 1;
	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (free(numbers), 0);
	*head = node;
	while (i < ac)
	{
		node->pos = i;
		node->number = numbers[i - 1];
		if (i++ != ac - 1)
		{
			node->next = (t_pile *)malloc(sizeof(t_pile));
			if (!(node->next))
				return (free(numbers), free_pile(head), 0);
			(node->next)->previous = node;
			node = node->next;
		}
	}
	(*head)->previous = node;
	node->next = *head;
	return (free(numbers), 1);
}

int	main(int ac, char **av)
{
	t_pile	**pileA;
	t_pile	**pileB;
	int		*numbers;

	pileA = (t_pile **)malloc(sizeof(t_pile *));
	if (!pileA)
		return (ft_printf("Error\n"), 1);
	numbers = trans_to_p_int(ac, av);
	if (!numbers)
		return (ft_printf("Error\n"), free(pileA), 1);
	pileB = (t_pile **)malloc(sizeof(t_pile *));
	if (!pileB)
		return (ft_printf("Error\n"), free(numbers), free(pileA), 1);
	if (!set_pile(pileA, ac, numbers))
		return(ft_printf("Error\n"), free(pileB), free(pileA), 1);
	*pileB = NULL;
	if (ac >= 2 && !check_sort(pileA))
		turk_algorithm(ac, pileA, pileB);
	free_pile(pileA);
	free_pile(pileB);
	return (EXIT_SUCCESS);
}
