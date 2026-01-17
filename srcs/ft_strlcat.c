/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vnaoussi <vnaoussi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 23:44:53 by vnaoussi          #+#    #+#             */
/*   Updated: 2026/01/16 16:16:47 by vnaoussi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "push_swap.h"

int	ft_strlcat(char *dest, const char *src, int size)
{
	int		i;
	int		j;
	int		src_len;

	i = 0;
	if (dest == NULL || src == NULL)
		return (0);
	src_len = ft_strlen(src);
	while (dest[i] && i < size)
		i++;
	if (i == size)
		return (i + src_len);
	j = 0;
	while (src[j] && j < size - i - 1)
	{
		dest[i + j] = src[j];
		j++;
	}
	dest[i + j] = '\0';
	return (i + src_len);
}
