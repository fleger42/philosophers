/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:33:10 by fleger            #+#    #+#             */
/*   Updated: 2019/11/08 13:29:53 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*destination;
	unsigned char	*source;

	destination = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (n--)
	{
		*destination++ = *source;
		if (*source == (unsigned char)c)
			return (destination);
		source++;
	}
	return (NULL);
}
