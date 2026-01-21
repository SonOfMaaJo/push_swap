/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_checker.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 09:32:27 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/20 12:21:17 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_CHECKER_H
# define PUSH_SWAP_CHECKER_H
# include "../libft/libft.h"

typedef	struct s_pile
{
	int				number;
	struct s_pile	*next;
	struct s_pile	*previous;
}	t_pile;

void	swap(t_pile **pile);
int		push(t_pile **pileA, t_pile **pileB);
void	rotate(t_pile **pile);
void	rev_rotate(t_pile **pile);
void	*free_pile(t_pile **pile);
int		check_sort(t_pile **pile);
int		trans_args_to_pints(int ac, char **av, int **numbers);
void	free_args(char **args);
int		process_check(t_pile **pileA, t_pile **pileB);

# endif
