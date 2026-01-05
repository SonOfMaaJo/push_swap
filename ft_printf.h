/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/21 01:47:56 by vnaoussi          #+#    #+#             */
/*   Updated: 2025/11/22 20:44:31 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <stddef.h>
# include <stdint.h>

void	ft_printarg(char format, va_list args, int *len);
int		ft_putchar(char c);
int		ft_putstr(char *str);
int		ft_putnbrbase(long c, char *base);
char	*ft_strchr(const char *s, int c);
int		ft_printf(const char *format, ...);
size_t	ft_strlen(char *str);
void	ft_perfdivp(unsigned int c, size_t base_len, char *base, int *len);
void	ft_printp(void *p, int *len);

#endif
