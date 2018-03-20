/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 13:21:01 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/26 13:21:02 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*m;
	unsigned char	k;

	i = 0;
	m = (unsigned char *)s;
	k = (unsigned char)c;
	while (i < n)
	{
		if (m[i] == k)
			return (&m[i]);
		i++;
	}
	return (NULL);
}
