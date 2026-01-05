/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:27:55 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/04 16:18:39 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "ft_printf.h"

typedef	struct s_pile
{
	int				number;
	int				pos;
	struct s_pile	*next;
	struct s_pile	*previous;
}	t_pile;

void	swap(t_pile **pile);
void	push(t_pile **pileA, t_pile **pileB);
void	rotate(t_pile **pile);
void	rev_rotate(t_pile **pile);
void	free_pile(t_pile **pile);
int		ft_atoi(const char *nptr);

# endif

