/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/06 12:07:09 by fleger            #+#    #+#             */
/*   Updated: 2019/11/15 16:19:34 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_aff(int n, int fd)
{
	if (n >= 10)
	{
		ft_aff(n / 10, fd);
		ft_aff(n % 10, fd);
	}
	else
		ft_putchar_fd(n + 48, fd);
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == -2147483648)
	{
		write(fd, "-2147483648", 12);
		return ;
	}
	if (n < 0)
	{
		n = -1 * n;
		write(fd, "-", 1);
	}
	ft_aff(n, fd);
}
