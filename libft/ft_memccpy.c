/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcppy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvinogra <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 16:19:54 by vvinogra          #+#    #+#             */
/*   Updated: 2017/10/25 16:19:55 by vvinogra         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*src1;
	unsigned char	*dst1;
	unsigned char	s;

	i = 0;
	src1 = (unsigned char *)src;
	dst1 = (unsigned char *)dst;
	s = (unsigned char)c;
	while (i < n)
	{
		dst1[i] = src1[i];
		if (src1[i] == s)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
