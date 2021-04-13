/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 16:12:51 by fleger            #+#    #+#             */
/*   Updated: 2019/11/16 17:33:55 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*first;
	t_list	*liste;

	if (*lst == NULL || lst == NULL)
		return ;
	first = *lst;
	liste = NULL;
	while (first)
	{
		if (first->next)
			liste = first->next;
		else
			liste = NULL;
		del(first);
		free(first);
		first = liste;
	}
	*lst = NULL;
}
