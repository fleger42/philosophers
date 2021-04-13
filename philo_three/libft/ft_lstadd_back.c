/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 17:22:22 by fleger            #+#    #+#             */
/*   Updated: 2019/11/16 16:38:44 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *actuel;

	if (*alst && alst)
	{
		actuel = *alst;
		while (actuel->next != NULL)
			actuel = actuel->next;
		actuel->next = new;
		new->next = NULL;
	}
	else if (alst)
		*alst = new;
}
