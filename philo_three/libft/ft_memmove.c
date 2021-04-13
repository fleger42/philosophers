/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:45:56 by fleger            #+#    #+#             */
/*   Updated: 2019/11/08 14:02:55 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;
	size_t			i;

	if (dst == NULL && src == NULL)
		return (NULL);
	i = 1;
	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	if (source <= destination)
		while (i <= n)
		{
			destination[n - i] = source[n - i];
			i++;
		}
	else
		while (n--)
			*destination++ = *source++;
	return (dst);
}
