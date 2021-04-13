/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/05 17:36:46 by fleger            #+#    #+#             */
/*   Updated: 2019/11/15 16:44:14 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	int		i;

	i = 0;
	if (!(tab = malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (s[start] && i < (int)len)
		tab[i++] = s[start++];
	tab[i] = '\0';
	return (tab);
}
