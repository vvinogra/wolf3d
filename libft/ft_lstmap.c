/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 15:11:54 by vvinogra          #+#    #+#             */
/*   Updated: 2017/11/02 15:11:55 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f) (t_list *elem))
{
	t_list	*new;
	t_list	*first;
	t_list	*start;

	if (!lst || !f)
		return (NULL);
	first = f(lst);
	new = ft_lstnew(first->content, first->content_size);
	if (!new)
		return (NULL);
	start = new;
	lst = lst->next;
	while (lst)
	{
		first = f(lst);
		new->next = ft_lstnew(first->content, first->content_size);
		if (!(new->next))
			return (NULL);
		new = new->next;
		lst = lst->next;
	}
	return (start);
}
