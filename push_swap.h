/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:27:55 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/08 02:41:40 by vnaoussi         ###   ########.fr       */
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
int		push(t_pile **pileA, t_pile **pileB);
void	update_pos(t_pile **pile);
void	rotate(t_pile **pile);
void	rev_rotate(t_pile **pile);
void	free_pile(t_pile **pile);
int		ft_atoi(const char *nptr);
void	print_pile(t_pile **pile);
int		check_sort(t_pile **pile);
char	*rotate_up(int costA, int cost_B, t_pile **pileA, t_pile **pileB);
char	*rotate_down(int costA, int cost_B, t_pile **pileA, t_pile **pileB);
char	*rotate_upA_DB(int costA, int costB, t_pile **pileA, t_pile **pileB);
char	*rotate_DA_upB(int costA, int costB, t_pile **pileA, t_pile **pileB);
int		turk_algorithm(int ac, t_pile **pileA, t_pile **pileB);
int		ccost(int len, int lenB, int pos, int pos_target);
int		*get_cost(int ac, int len, t_pile **pileA, t_pile **pileB);
char	*mov(int ac, int len, int *cost, t_pile **pileA, t_pile **pileB);
int		ft_strlcat(char *dst, const char *src, int size);
# endif