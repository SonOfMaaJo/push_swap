/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 16:57:37 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 16:58:31 by vnaoussi         ###   ########.fr       */
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

static int	set_pile(t_pile **head, int size, int *numbers)
{
	t_pile	*node;
	int		i;

	i = 0;
	node = (t_pile *)malloc(sizeof(t_pile));
	if (!node)
		return (free(numbers), 0);
	*head = node;
	while (i < size)
	{
		node->pos = i + 1;
		node->number = numbers[i];
		if (i != size - 1)
		{
			node->next = (t_pile *)malloc(sizeof(t_pile));
			if (!(node->next))
				return (free(numbers), free_pile(head), 0);
			(node->next)->previous = node;
			node = node->next;
		}
		i++;
	}
	(*head)->previous = node;
	node->next = *head;
	return (free(numbers), 1);
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
	int		*numbers;
	int		size;

	if (ac < 2)
		return (EXIT_SUCCESS);
	pilea = (t_pile **)malloc(sizeof(t_pile *));
	if (!pilea)
		return (ft_printf("Error\n"), 1);
	numbers = trans_to_p_int(ac, av, &size);
	if (!numbers)
		return (ft_printf("Error\n"), free(pilea), 1);
	pileb = (t_pile **)malloc(sizeof(t_pile *));
	if (!pileb)
		return (ft_printf("Error\n"), free(numbers), free(pilea), 1);
	if (!set_pile(pilea, size, numbers))
		return (ft_printf("Error\n"), free(pileb), free(pilea), 1);
	*pileb = NULL;
	if (!check_sort(pilea))
		turk_algorithm(size + 1, pilea, pileb);
	free_pile(pilea);
	free_pile(pileb);
	return (EXIT_SUCCESS);
}
