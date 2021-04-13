/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:23:12 by fleger            #+#    #+#             */
/*   Updated: 2019/11/16 17:35:49 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		is_charset(char c, char *charset)
{
	int i;

	i = 0;
	if (charset[0] == '\0')
		return (0);
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tab;
	int		length;
	int		i;

	i = 0;
	length = ft_strlen(s1) - 1;
	while (s1[i] && is_charset(s1[i], (char *)set))
		i++;
	while (length > i && is_charset(s1[length], (char *)set))
		length--;
	if (!(tab = malloc(sizeof(char) * (length - i + 2))))
		return (NULL);
	tab[length - i + 1] = '\0';
	while (length >= i)
	{
		tab[length - i] = s1[length];
		length--;
	}
	return (tab);
}
