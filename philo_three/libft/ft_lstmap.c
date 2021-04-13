/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fleger <fleger@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 13:38:51 by fleger            #+#    #+#             */
/*   Updated: 2019/11/16 17:31:25 by fleger           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *new;
	t_list *retour;

	if (lst == NULL)
		return (NULL);
	new = (t_list *)malloc(sizeof(t_list));
	new->content = f(lst->content);
	new->next = NULL;
	retour = new;
	while (lst->next)
	{
		lst = lst->next;
		if (!(new = ft_lstnew(f(lst->content))))
		{
			ft_lstclear(&retour, del);
			return (NULL);
		}
		ft_lstadd_back(&retour, new);
	}
	new->next = NULL;
	return (retour);
}
