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

void	free_args(char **args)
{
	int	i;

	i = 0;
	if (!args)
		return ;
	while (args[i++])
		free(args[i - 1]);
	free(args);
}

int	main(int ac, char **av)
{
	t_pile	**pilea;
	t_pile	**pileb;
	int		**nbs;
	int		size;

	if (ac < 2)
		return (EXIT_SUCCESS);
	nbs = (int **)malloc(sizeof(int *));
	pilea = (t_pile **)malloc(sizeof(t_pile *));
	if (!pilea || !nbs)
		return (ft_printf("Error\n"), free(pilea), free(nbs), 1);
	size = trans_args_to_pints(ac, av, nbs);
	if (size == 0)
		return (ft_printf("Error\n"), free(pilea), free(nbs), 1);
	pileb = (t_pile **)malloc(sizeof(t_pile *));
	if (!pileb)
		return (ft_printf("Error\n"), free(*nbs), free(nbs), free(pilea), 1);
	if (!set_pile(pilea, *nbs, size))
		return (ft_printf("Error\n"), free(pileb), free(pilea), 1);
	*pileb = NULL;
	if (process_check(pilea, pileb))
	{
		if (check_sort(pilea) && !(*pileb))
			return (ft_printf("OK\n"), free_pile(pilea), free_pile(pileb), 0);
		else
			return (ft_printf("KO\n"), free_pile(pilea), free_pile(pileb), 0);
	}
	else
		return (ft_printf("Error\n"), free_pile(pilea), free_pile(pileb), 1);
}
