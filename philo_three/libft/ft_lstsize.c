/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:55:01 by fleger            #+#    #+#             */
/*   Updated: 2019/11/16 16:11:04 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*actuel;
	int		i;

	actuel = lst;
	i = 0;
	if (actuel == NULL)
		return (0);
	while (actuel != NULL)
	{
		actuel = actuel->next;
		i++;
	}
	return (i);
}
