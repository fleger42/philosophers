/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 08:45:47 by fleger            #+#    #+#             */
/*   Updated: 2019/11/12 14:17:55 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_nbr_c(int n)
{
	int nbr_c;

	nbr_c = 1;
	if (n == -2147483648)
		return (11);
	if (n < 0)
	{
		nbr_c++;
		n = -n;
	}
	while (n >= 10)
	{
		nbr_c++;
		n = n / 10;
	}
	return (nbr_c);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			length;
	long int	n2;

	n2 = (long int)n;
	length = ft_nbr_c(n);
	if (!(str = malloc(sizeof(char) * (length + 1))))
		return (NULL);
	if (n2 < 0)
	{
		n2 = -n2;
		str[0] = '-';
	}
	str[length] = '\0';
	while (n2 >= 10)
	{
		str[length-- - 1] = (n2 % 10) + 48;
		n2 = n2 / 10;
	}
	str[length - 1] = n2 + 48;
	return (str);
}
