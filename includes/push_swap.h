/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/03 16:27:55 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/23 16:48:34 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "../libft/libft.h"
# define THRESHOLD 220000

typedef struct s_pile
{
	int				number;
	int				pos;
	struct s_pile	*next;
	struct s_pile	*previous;
}	t_pile;
void	swap(char *name, t_pile **pile, char *operations, int s);
int		push(char *name, t_pile **pileA, t_pile **pileB, char *op, int s);
void	rotate(int cost, char *name, t_pile **pile, char *operations, int s);
void	rev_rotate(int cost, char *name, t_pile **pile, char *op, int s);
void	*free_pile(t_pile **pile);
long	ps_atoi(const char *nptr);
int		check_sort(t_pile **pile);
char	*rotate_up(int costA, int cost_B, t_pile **pileA, t_pile **pileB);
char	*rotate_down(int costA, int cost_B, t_pile **pileA, t_pile **pileB);
char	*rotate_upa_db(int costA, int costB, t_pile **pileA, t_pile **pileB);
char	*rotate_da_upb(int costA, int costB, t_pile **pileA, t_pile **pileB);
int		get_pos_target_in_a(int number, t_pile **pileA);
void	reorder(int len, t_pile **pile, char **operations);
int		turk_algorithm(int ac, t_pile **pileA, t_pile **pileB);
int		ccost(int len, int lenB, int pos, int pos_target);
int		*get_cost(int ac, int len, t_pile **pileA, t_pile **pileB);
char	*mov(int ac, int len, int *cost, t_pile **pileA, t_pile **pileB);
int		ft_strcmp(const char *s1, const char *s2);
int		*trans_to_p_int(int ac, char **av, int *size);
void	free_args(char **args);

#endif
