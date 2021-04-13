/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 15:39:12 by fleger            #+#    #+#             */
/*   Updated: 2019/11/07 17:18:19 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;
	char	*tab;

	tab = (char*)s;
	i = 0;
	while (i < n)
	{
		if (tab[i] == c)
		{
			return ((void*)s + i);
		}
		i++;
	}
	return (NULL);
}
