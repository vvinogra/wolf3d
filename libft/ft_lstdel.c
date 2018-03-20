/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/02 13:51:34 by vvinogra          #+#    #+#             */
/*   Updated: 2017/11/02 13:51:34 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *tmp;

	if (alst == NULL || *alst == NULL || del == NULL)
		return ;
	while (*alst)
	{
		tmp = *alst;
		(*alst) = (*alst)->next;
		del(tmp->content, tmp->content_size);
		free(tmp);
		tmp = NULL;
	}
}
