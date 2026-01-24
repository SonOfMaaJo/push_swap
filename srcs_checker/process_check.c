/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 11:04:41 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/20 15:41:51 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_checker.h"

int	do_operation(char *operation, t_pile **pileA, t_pile **pileB)
{
	if (ft_strcmp("sa\n", operation) == 0)
		return (swap(pileA), 1);
	else if (ft_strcmp("sb\n", operation) == 0)
		return (swap(pileB), 1);
	else if (ft_strcmp("ss\n", operation) == 0)
		return (swap(pileA), swap(pileB), 1);
	else if (ft_strcmp("pa\n", operation) == 0)
		return (push(pileB, pileA));
	else if (ft_strcmp("pb\n", operation) == 0)
		return (push(pileA, pileB));
	else if (ft_strcmp("ra\n", operation) == 0)
		return (rotate(pileA), 1);
	else if (ft_strcmp("rb\n", operation) == 0)
		return (rotate(pileB), 1);
	else if (ft_strcmp("rr\n", operation) == 0)
		return (rotate(pileA), rotate(pileB), 1);
	else if (ft_strcmp("rra\n", operation) == 0)
		return (rev_rotate(pileA), 1);
	else if (ft_strcmp("rrb\n", operation) == 0)
		return (rev_rotate(pileB), 1);
	else if (ft_strcmp("rrr\n", operation) == 0)
		return (rev_rotate(pileA), rev_rotate(pileB), 1);
	else
		return (0);
}

int	process_check(t_pile **pileA, t_pile **pileB)
{
	char	*operation;

	operation = get_next_line(0);
	while (operation)
	{
		if (!do_operation(operation, pileA, pileB))
			return (free(operation), 0);
		free(operation);
		operation = get_next_line(0);
	}
	return (1);
}
