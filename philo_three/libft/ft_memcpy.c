/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 12:15:35 by fleger            #+#    #+#             */
/*   Updated: 2019/11/08 13:30:21 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*destination;
	const char	*source;

	if (dst == NULL && src == NULL)
		return (NULL);
	destination = dst;
	source = src;
	while (n > 0)
	{
		*destination++ = *source++;
		n--;
	}
	return (dst);
}
